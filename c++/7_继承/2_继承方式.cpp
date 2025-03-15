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

// *公共继承
class Son1 : public Base1
{
public:
    void func()
    {
        m_A = 10; // 父类的公共权限成员 到了子类依然是公共权限
        m_B = 10; // 父类的保护权限成员 到了子类依然是保护权限
        // m_C = 10; //error 父类的私有权限成员 子类访问不到
    }
};

// *保护继承
class Son2 : protected Base1
{

public:
    void func()
    {
        m_A = 10; // 父类的公共权限成员 到了子类变为保护权限
        m_B = 10; // 父类的保护权限成员 到了子类依然是保护权限
        // m_C = 10; //error 父类的私有权限成员 子类访问不到
    }
};

// *私有继承
class Son3 : private Base1
{
public:
    void func()
    {
        m_A = 10; // 父类的公共权限成员 到了子类变为私有权限
        m_B = 10; // 父类的保护权限成员 到了子类变为私有权限
        // m_C = 10; //error 父类的私有权限成员 子类访问不到
    }
};

class GrandSon3 : public Son3
{
public:
    void func()
    {
        // m_C = 10; // error Son3父类的私有权限成员 子类访问不到
    }
};

int main()
{
    Son1 s1;
    s1.m_A = 100;
    // s1.m_B = 100; //error 到Son1中m_B是保护权限 类外访问不到

    Son2 s2;
    // s2.m_A = 1000; //error 到Son2中m_A是保护权限 类外访问不到

    Son3 s3;
    // s3.m_A = 10000; // error 到Son2中m_A是私有权限 类外访问不到
}