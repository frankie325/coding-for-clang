#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test1()
{
    /*
        在 C++11 之前的标准中，连续的右尖括号 >> 会被编译器误解为右移运算符，
        所以需要在两个右尖括号之间加上空格来避免歧义。
    */
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    // 将容器元素插入到vector v中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // 通过大容器，把所有数据遍历一遍
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        // (*it) ------ vector<int>
        // vector<int> innerV = (*it);
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}

int main()
{
    test1();
    return 0;
}