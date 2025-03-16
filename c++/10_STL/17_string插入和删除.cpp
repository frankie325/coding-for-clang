#include <iostream>
#include <string>
using namespace std;

/*
函数原型：

string& insert(int pos, const char* s);  //插入字符串
string& insert(int pos, const string& str);  //插入字符串
string& insert(int pos, int n, char c); //在指定位置插入n个字符c
string& erase(int pos, int n = npos); //删除从Pos开始的n个字符
*/

int main()
{
    string str = "hello";
    str.insert(1, "111"); // h111ello
    cout << str << endl;

    str.erase(1, 3); // 从1号位置开始3个字符
    cout << str << endl;

    return 0;
}