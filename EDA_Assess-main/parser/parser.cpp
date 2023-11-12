
#include <iostream>
#include <fstream>
#include "../database/database.h"

std::string FileName = R"(/home/uwieiq/project/eda/EDA_Assess-main/benchmarks/case0.txt)";

void Loading()
{

    std::ifstream Init;
    Init.open(FileName, std::ios::in);

    if (Init.is_open() == false)
    {
        std::cout << "false to open file.";
        return;
    }
    std::string Buf;
    int i = 0;
    int j = 0;
    int k = 0;
    while (Init >> Buf)
    {
        if (Buf == "DieSize")
        {
            Init >> LMap;
            Init >> WMap;
        }
        if (Buf == "NumInstances")
        {
            Init >> NumInstances;
            PinCollection = new Pin[NumInstances - 1];
        }
        if (Buf == "Inst")
        {
            Init >> PinCollection[i].name;
            PinCollection[i].PinID = i;
            i++;
        }
        if (Buf == "NumNets")
        {
            Init >> NumNets;
            NetsCollection = new Net[NumNets-1];//有待重新考虑
        }
        if (Buf == "Net")
        {
            Init >> NetsCollection[j].name;
            Init >> NetsCollection[j].Nums;
            NetsCollection[j].AssemblePin = new std::string[NetsCollection[j].Nums - 1];
            NetsCollection[j].IDofPin = new int[NetsCollection[j].Nums - 1];
            j++;
        }
        if (Buf == "Pin")
        {
            Init >> NetsCollection[j].AssemblePin[k];
            for (int a = 0; a < NumInstances - 1; a++)
            {
                if (NetsCollection[j].AssemblePin[k] == PinCollection[a].name)
                {
                    NetsCollection[j].IDofPin[k] = PinCollection[a].PinID;
                }
            } // 读取时顺便初始化各点的编号

            k++;
            if (k == NetsCollection[j].Nums)
                k = 0;
        }
    }
    Init.close();
    return;
}
