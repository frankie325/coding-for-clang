#include <iostream>
using namespace std;

class MyInteger
{
public:
    friend ostream &operator<<(ostream &cout, const MyInteger &i);

    MyInteger()
    {
        m_num = 10;
    }

    // *重载前置++运算符
    MyInteger &operator++()
    {
        // 先进行++运算
        m_num++;
        // 再将自身返回，支持嵌套运算++(++myInt)
        return *this;
    }
    // *重载后置++运算符，int为占位参数，可以用于区分前置和后置递增
    MyInteger operator++(int) // !后置递增返回的是值，而不是引用
    {
        // 先 记录当时结构
        MyInteger temp = *this;
        // 后 递增
        m_num++;
        // 最后将记录结构返回
        return temp;
    }

private:
    int m_num;
};

// 利用全局函数重载左移运算符
ostream &operator<<(ostream &cout, const MyInteger &i) // 临时对象（如 myInt++ 的返回值）只能绑定到常量引用。非常量引用不能接受临时对象作为参数，所以这里要加const
{
    cout << "m_num = " << i.m_num << endl;
    return cout; // 返回cout支持链式调用 如：cout << p << endl;
};

int main()
{
    // 注意：后置++不能嵌套
    // int a = 1;
    // int b = (a++)++;
    MyInteger myInt;
    cout << ++(++myInt) << endl; // 12
    cout << myInt++ << endl;     // 12
    cout << myInt << endl;       // 13
    return 0;
}