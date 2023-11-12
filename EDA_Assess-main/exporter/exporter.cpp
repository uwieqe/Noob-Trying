
#include<iostream>
#include"exporter.h"
#include "../database/database.h"
#include<fstream>

void OutPut()
{
    std::ofstream Out;
    Out.open(R"(/home/uwieiq/project/eda/EDA_Assess-main/benchmarks/out.txt)");

    for(int i=0;i<NumInstances-1;i++)
    {
        Out<<PinCollection[i].name<<" "<<PinCollection[i].x<<" "<<PinCollection[i].y<<"\n";
        
    }


    Out.close();
    return;

}


