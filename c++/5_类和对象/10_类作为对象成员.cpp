#include <iostream>
#include <string>
using namespace std;

class Phone
{
public:
    string name;
    Phone(string n)
    {
        name = n;
        cout << "phone的构造函数" << endl;
    }

    ~Phone()
    {
        cout << "phone的析构函数" << endl;
    }
};

class Person
{
public:
    string name;
    Phone phone; // phone实例作为Person类的成员

    // phone(p_n) 相当于隐式转换写法， Phone phone = p_n，调用Phone类的构造函数
    Person(string n, string p_n) : name(n), phone(p_n)
    {
        cout << "person的构造函数" << endl;
    }
    ~Person()
    {
        cout << "person的析构函数" << endl;
    }
};

int main()
{
    /*
        构造函数执行顺序：入栈顺序
            phone的构造函数
            person的构造函数
        析构函数执行顺序：出栈顺序
            person的析构函数
            phone的析构函数
    */
    Person p1("kfg", "iphone");
}