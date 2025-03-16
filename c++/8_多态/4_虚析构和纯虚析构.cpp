#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal 构造函数调用！" << endl;
    }

    // 析构函数加上virtual关键字，变成虚析构函数
    // virtual ~Animal()
    // {
    //     cout << "Animal虚析构函数调用！" << endl;
    // }

    virtual ~Animal() = 0;
};

/*
*虚析构和纯虚析构共性：
    可以解决父类指针释放子类对象
    都需要有具体的函数实现
*虚析构和纯虚析构区别：
    如果是纯虚析构，该类属于抽象类，无法实例化对象
*/
Animal::~Animal()
{
    cout << "Animal 纯虚析构函数调用！" << endl;
}

class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat构造函数调用" << endl;
        m_Name = new string(name);
    }

    ~Cat()
    {
        cout << "Cat析构函数调用!" << endl;
        if (this->m_Name != NULL)
        {
            delete m_Name;
            m_Name = NULL;
        }
    }
    string *m_Name;
};

int main()
{
    Animal *animal = new Cat("Tom");

    // !通过父类指针去释放，会导致子类对象可能清理不干净（子类析构函数并没有调用），造成内存泄漏
    // 怎么解决？给基类增加一个虚析构函数
    // 虚析构函数就是用来解决通过父类指针释放子类对象
    delete animal;
}