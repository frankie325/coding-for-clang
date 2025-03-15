#include <iostream>
using namespace std;

class Person
{
public:
    int age;
    void show1()
    {
        cout << "show1" << endl;
    }

    void show2()
    {
        // 加上限制防止报错
        if (this == NULL)
        {
            return;
        }
        // 报错原因是因为传入的指针是NULL
        cout << "show1" << this->age << endl;
    }
};

int main()
{
    Person *p1 = NULL;
    // 控制针也可以访问成员函数
    p1->show1();
    p1->show2(); // error
    return 0;
}