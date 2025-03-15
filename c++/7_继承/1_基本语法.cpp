#include <iostream>
using namespace std;

class Parent
{
public:
    void show()
    {
        cout << "我是父类方法" << endl;
    }
};

// 继承：
// 语法： class 子类 ：继承方式 父类
class Son : public Parent
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
};

int main()
{
    Parent p;
    p.show();
    Son s;
    s.show();
}