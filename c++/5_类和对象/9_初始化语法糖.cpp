#include <iostream>
using namespace std;

class Person
{
public:
    int ma;
    int mb;
    int mc;
    // 传统初始化列表方式
    // Person(int a, int b, int c)
    // {
    //     ma = a;
    //     mb = b;
    //     mc = c;
    // }

    // 新初始化列表方式
    Person(int a, int b, int c) : ma(a), mb(b), mc(c)
    {
    }
};

int main()
{
    Person p1(1, 2, 3);
    cout << p1.ma << endl;
    cout << p1.mb << endl;
    cout << p1.mc << endl;
    return 0;
}