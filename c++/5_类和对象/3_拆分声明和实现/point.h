#pragma once // #pragma once 是一个预处理指令，用于防止头文件被多次包含
#include <iostream>
using namespace std;
// 类声明
class Point
{
private:
public:
    int x;
    int y;
    void setX(int);
    void setY(int);
};