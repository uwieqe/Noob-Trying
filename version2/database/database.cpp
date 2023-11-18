#include <iostream>
#include "database.h"
#include <string>
#include<cmath>
int LMap, WMap;
int **Map;
int NumNets, NumInstances;
Pin *PinCollection;
Net *NetsCollection;

void InitData()
{
    WMap=1+sqrt(NumInstances);
    if(LMap>=NumInstances)
    LMap=NumInstances;
    std::cout<<WMap<<LMap<<std::endl;
    
    Map = new int *[WMap];
    for (int i = 0; i < WMap ;i++)
    {
        Map[i] = new int[LMap];
        
    }
    for (int i = 0; i < WMap; i++)
    {
        for (int j = 0; j < WMap; j++)
        Map[i][j]=-1;
    }
    
    
}
void FreeData()
{
    for (int i = 0; i < WMap-1; i++)
    {
        delete Map[i];
    }
    Map = NULL;
    PinCollection = NULL;
    NetsCollection = NULL;

}
