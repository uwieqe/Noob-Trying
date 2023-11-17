
#include<iostream>
#include"exporter.h"
#include "../database/database.h"
#include<fstream>

void OutPut()
{
    std::ofstream Out;
    Out.open(R"(../benchmarks/out.txt)");

    for(int i=0;i<NumInstances;i++)
    {
        Out<<PinCollection[i].name<<" "<<PinCollection[i].x<<" "<<PinCollection[i].y<<"\n";
        
    }


    Out.close();
    return;

}


