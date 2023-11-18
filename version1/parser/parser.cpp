
#include <iostream>
#include <fstream>
#include "../database/database.h"

std::string FileName = R"(../benchmarks/case1.txt)";

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
            std::cout<<"不错0"<<std::endl;
        }
       if (Buf == "NumInstances")
        {
            Init >> NumInstances;
            PinCollection = new Pin[NumInstances];
            std::cout<<"不错1 "<<NumInstances<<std::endl;
        }
        if (Buf == "Inst")
        {
            std::cout<<i;
            Init >> PinCollection[i].name;
            PinCollection[i].PinID = i;
            PinCollection[i].IsMap = false;
            std::cout<<" 不错2 "<<PinCollection[i].name<<std::endl;
            i++;
        }
        if(Buf == "NumNets")
        {
            Init >> NumNets;
            NetsCollection = new Net[NumNets];//有待重新考虑
            std::cout<<"不错3"<<std::endl;
        }
       if(Buf == "Net")
        {
            Init >> NetsCollection[j].name;
            Init >> NetsCollection[j].Nums;
            NetsCollection[j].AssemblePin = new std::string[NetsCollection[j].Nums ];
            NetsCollection[j].IDofPin = new int[NetsCollection[j].Nums ];
            j++;
            std::cout<<"不错4"<<std::endl;
        }
        if (Buf == "Pin")
        {
            Init >> NetsCollection[j-1].AssemblePin[k];
            for (int a = 0; a < NumInstances; a++)
            {
                if (NetsCollection[j-1].AssemblePin[k] == PinCollection[a].name)
                {
                    NetsCollection[j-1].IDofPin[k] = PinCollection[a].PinID;
                }
            } // 读取时顺便初始化各点的编号

            k++;
            if (k == NetsCollection[j-1].Nums)
                k = 0;
            std::cout<<"不错5"<<std::endl;
        }
    }
    Init.close();
    return;
}
