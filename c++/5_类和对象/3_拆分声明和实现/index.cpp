#include <iostream>
#include "point.h"
#include "circle.h"

using namespace std;

/*
运行命令：编译所有文件
g++ -std=c++11 index.cpp point.cpp circle.cpp -o index
*/ 
int main()
{
    Point p;
    p.setX(0);
    p.setY(10);

    Circle c;
    c.setX(0);
    c.setY(0);
    c.setRadius(10);

    c.getPosition(p);
    return 0;
}