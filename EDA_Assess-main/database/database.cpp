#include <iostream>
#include "database.h"
#include <string>

int LMap, WMap;
int **Map;
int NumNets, NumInstances;
Pin *PinCollection;
Net *NetsCollection;

void InitData()
{
    Map = new int *[WMap-1];
    for (int i = 0; i < WMap-1 ;i++)
    {
        Map[i] = new int[LMap-1];
        
    }
    for (int i = 0; i < WMap-1; i++)
    {
        for (int j = 0; j < WMap-1; j++)
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
