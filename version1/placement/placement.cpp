#include <iostream>
#include "../database/database.h"
#include "../parser/parser.h"
#include "placement.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../exporter/exporter.h"

int min = INT_MAX; // 记录最小值
int Lenth = 0;
// void InitAdjancy()
// {
//     ShEdge=new ShortEdge[NumInstances-1];
//     AdjanctNatrixTable = new int *[NumInstances - 1];
//     for (int i = 0; i < NumInstances - 1; i++)
//     {
//         AdjanctNatrixTable[i] = new int[NumInstances - 1];
//     }
//     for (int i = 0; i < NumInstances - 1; i++)
//     {
//         for (int j = 0; j < NumInstances - 1; j++)
//         {
//             AdjanctNatrixTable[i][j] = INT_MAX;
//         }
//     }
// }//初始化邻接矩阵 和 最短边辅助数组

// void AdjanctNatrix()
// {
//     for (int i = 0; i < NumInstances - 1; i++)
//     {
//         if (PinCollection[i].IsMap == true)
//         {
//             for (int j = 0; j < NumInstances - 1; j++)
//             {
//                 if (PinCollection[j].IsMap == true)
//                 {
//                     AdjanctNatrixTable[i][j] = pow(abs(PinCollection[i].x - PinCollection[j].x), 2) + pow(abs(PinCollection[i].y - PinCollection[j].y), 2);
//                 }
//             }
//         }
//     }
// } // 更新场上所有点的邻接矩阵

// void FreeAdjance()
// {
//     for (int i = 0; i < NumInstances-1; i++)
//     {
//         delete AdjanctNatrixTable[i];
//     }
// }//释放内存
// int Min(int p)
// {
//     int min;
//     int ret;
//     for (int i; i < NumInstances; i++)
//     {
//         if (PinCollection[p].IsMap == true)
//         {
//             if (PinCollection[i].IsMap==true)
//             {
//                 if (AdjanctNatrixTable[p][i] < min)
//                 {
//                     min = AdjanctNatrixTable[p][i];
//                 }
//             }
//         }
//     }
//     return ret;
// } // 求一个点到其他点的所有距离中的最小值 （点的号码为p）

// int PrimArithmetic() // prim算法 求最小生成树 返回最小长度
// {
//     for(int i=0;i<NumNets-1;i++)
//     {
//         for(int j=0;j<NumInstances-1;j++)
//         {
//             ShEdge[j].last=NetsCollection[i].IDofPin[0];
//             ShEdge[j].lowcast=AdjanctNatrixTable[NetsCollection[i].IDofPin[0]][j];
//         }

//     }
// }
void Place_Main(int num)
{
    int tmp = INT_MAX; // 记录每层的最小
    if (num == NumInstances)
    {
        if (Lenth <= min)
        {
            min = Lenth;
            OutPut(); // 生成文件
        }
        return;
    }
    if (num < NumInstances)
    {
        for (int i = 0; i < WMap; i++)
        {
            for (int j = 0; j < LMap; j++)
            {
                if (Map[i][j] == -1 && PinCollection[num].IsMap == false)
                {
                    Map[i][j] = num;
                    PinCollection[num].IsMap = true;
                    PinCollection[num].x = i;
                    PinCollection[num].y = j;
                    if (tmp >= (Lenth + Increase(num)))
                    {
                        tmp = Lenth + Increase(num);
                        Lenth = tmp;
                        Place_Main(num + 1);
                        Lenth -= Increase(num);
                    }
                    Map[i][j] = -1;
                    PinCollection[num].IsMap = false;
                }
            }
        }
    }
} // 待优化的  添加剪枝  每次都长度计算
// 剪枝 只能长不能短

int Calculate()
{
    // int **VistTable=new int *[NumInstances-1];
    // for (int i = 0; i < NumInstances-1-1 ;i++)
    // {
    //     VistTable[i] = new int[NumInstances-1];

    // }//一个邻接矩阵 来记录两点间线长是否重复 记得释放内存
    int ret = 0;
    for (int i = 0; i < NumNets; i++)
    {
        for (int j = 0; j < NetsCollection[i].Nums - 1; j++)
        {
            if (PinCollection[NetsCollection[i].IDofPin[j]].IsMap == true && PinCollection[NetsCollection[i].IDofPin[j + 1]].IsMap == true)
            {
                ret += Distance(NetsCollection[i].IDofPin[j], NetsCollection[i].IDofPin[j + 1]);
            }
        }
    }
    return ret;
}

int Distance(int a, int b) // 计算a点和b点的距离
{
    int ret;
    ret = pow(abs(PinCollection[a].x - PinCollection[b].x), 2) + pow(abs(PinCollection[a].y - PinCollection[b].y), 2);
    return ret;
}

int Increase(int num)
{
    int ret = 0;
    for (int i = 0; i < NumNets; i++)
    {
        for (int j = 1; j < NetsCollection[i].Nums - 1; j++)
        {
            if (NetsCollection[i].IDofPin[j] == num)
            {
                if (PinCollection[NetsCollection[i].IDofPin[j]].IsMap == true && PinCollection[NetsCollection[i].IDofPin[j + 1]].IsMap == true)
                {
                    ret += Distance(NetsCollection[i].IDofPin[j], NetsCollection[i].IDofPin[j + 1]);
                }
                if (PinCollection[NetsCollection[i].IDofPin[j]].IsMap == true && PinCollection[NetsCollection[i].IDofPin[j - 1]].IsMap == true)
                {
                    ret += Distance(NetsCollection[i].IDofPin[j], NetsCollection[i].IDofPin[j - 1]);
                }
            }
        }
    }
    return ret;
}
