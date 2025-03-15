#include <cmath> // 添加数学函数库
#include "circle.h"

void Circle::setRadius(int num)
{
    radius = num;
}

void Circle::setX(int num)
{
    x = num;
}

void Circle::setY(int num)
{
    y = num;
}

// 获取点和圆的位置关系
void Circle::getPosition(Point point)
{
    double dx = point.x - x;
    double dy = point.y - y;
    double distance = sqrt(dx * dx + dy * dy);

    if (distance > radius)
    {
        cout << "点在圆外" << endl;
    }
    else if (distance < radius)
    {
        cout << "点在圆内" << endl;
    }
    else
    {
        cout << "点在圆上" << endl;
    }
}