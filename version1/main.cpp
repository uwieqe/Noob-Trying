#include "database/database.h"
#include "parser/parser.h"
#include "placement/placement.h"
#include<iostream>

int main()
{
    std::cout<<"你好"<<std::endl;
    Loading();
    std::cout<<"不错"<<std::endl;
    InitData();
    std::cout<<"加油"<<std::endl;
    Place_Main(0);
    std::cout<<"woc在跑了"<<std::endl;
    FreeData();
    std::cout<<"再见"<<std::endl;
    return 0;
}
 