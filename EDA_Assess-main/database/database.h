#ifndef DATABASE_H
#define DATABASE_H
#define INT_MAX 0x3f3f3f3f // 无穷大写这没关系吧
#include <string>

extern int LMap, WMap;
extern int **Map;
extern int NumNets, NumInstances;

class Pin
{
public:
    int x, y;
    std::string name;
    bool IsMap = false;
    int PinID;
};
class Net
{
public:
    int Nums;
    int *IDofPin; // ID or Pin
    std::string name;
    std::string *AssemblePin;
};
extern Pin *PinCollection;
extern Net *NetsCollection;
void InitData();
void FreeData();

#endif
