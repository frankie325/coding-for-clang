#include <iostream>

using namespace std; // 使用标准命名空间

int main()
{
    int n;
    //  如果不使用using namespace std;，则需要在cout和cin前加上std::
    // std::cin >> n; // 输入一个整数
    // std::cout << n << std::endl;
    cin >> n;
    cout << n << endl;
    return 0;
}