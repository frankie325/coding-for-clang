#pragma once // #pragma once 是一个预处理指令，用于防止头文件被多次包含
#include <iostream>
#include "point.h"
using namespace std;
// 类声明
class Circle
{
private:
    double radius; // 半径
    // 圆心
    int x;
    int y;

public:
    void setRadius(int);
    void setX(int);
    void setY(int);
    void getPosition(Point);
};