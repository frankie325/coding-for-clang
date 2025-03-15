#include <iostream>
#include <string>
using namespace std;
/*

struct和class的区别：

1.默认访问权限：

struct: 默认为 public
class: 默认为 private

2.继承权限：
struct: 默认 public 继承
class: 默认 private 继承

3.使用场景：
struct: 主要用于数据结构的简单集合
class: 用于更复杂的数据抽象和封装

4.设计思想：
struct: 保持与C语言的兼容性
class: 体现面向对象的封装特性
*/
// struct默认访问权限为public
struct Person1
{
    string name; // public
    int age;     // public

    void showInfo()
    { // public
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// class默认访问权限为private
class Person2
{
    string name; // private
    int age;     // private

public:
    void setInfo(string n, int a)
    {
        name = n;
        age = a;
    }

    void showInfo()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    // struct对象
    Person1 p1;
    p1.name = "Tom"; // 可以直接访问
    p1.age = 20;     // 可以直接访问
    p1.showInfo();

    // class对象
    Person2 p2;
    // p2.name = "Jerry";  // 错误：不能直接访问private成员
    // p2.age = 18;       // 错误：不能直接访问private成员
    p2.setInfo("Jerry", 18); // 必须通过public方法访问
    p2.showInfo();
}