#include <iostream>
#define PI 3.1415926
using namespace std;

// 设计一个圆类
class Circle
{
    // 访问权限：
    // public：公共权限     类内可以访问、类外可以访问
    // protected：保护权限  类内可以访问、类外不可以访问、子类可以访问父类
    // private：私有权限    类内可以访问、类外不可以访问、子类不可以访问父类
private:
    int id = 1; // C++11 的特性或更高版本编译才能直接初始化
public:
    // *类中的属性和行为统称为成员
    // int id = 1;
    // 属性
    // 半径
    int m_r;

    // 行为
    // 获取圆的周长
    double calculateZC()
    {
        return 2 * PI * m_r;
    }

    // 设置圆的半径
    void setRadius(int r)
    {
        m_r = r;
    }

    // 自己控制权限，可以通过方法访问私有属性
    int getId()
    {
        return id;
    }
};

int main()
{
    // 通过圆类，创建一个具体对象
    Circle c1;
    // cout << "圆的id为：" << c1.id << endl; //error
    cout << "圆的id为：" << c1.getId() << endl;
    // c1.setRadius(10);
    // c1.m_r = 10;

    cout << "圆的周长为：" << c1.calculateZC() << endl;
}