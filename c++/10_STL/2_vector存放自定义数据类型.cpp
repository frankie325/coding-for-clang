#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        mName = name;
        mAge = age;
    }

public:
    string mName;
    int mAge;
};

// 存放对象
void test01()
{
    vector<Person> v;

    // 创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // it为指向Person实例的指针
        // cout << "姓名：" << (*it).mName << "年龄：" << (*it).mAge << endl;
        cout << "姓名：" << it->mName << "年龄：" << it->mAge << endl;
    }
}

// 存放对象指针
void test02()
{
    vector<Person *> v;

    // 创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        // it为指向指针Person *的指针，二级指针
        Person *p = (*it);
        cout << "姓名：" << p->mName << "年龄：" << p->mAge << endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}