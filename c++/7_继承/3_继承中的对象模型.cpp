#include <iostream>
using namespace std;

class Base1
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son1 : public Base1
{
public:
    int m_D;
};

int main()
{
    // 大小为16字节
    // 父类中所有非静态成员属性都会被子类继承下去
    // 父类中私有成员属性 是被编译器给隐藏了，因此是访问不到的，但是确实是被继承下去了
    cout << "size of Son1 =" << sizeof(Son1) << endl;
}
