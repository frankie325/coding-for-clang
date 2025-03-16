#include <iostream>
using namespace std;

// #include "person.h" //error 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
// #include "person.cpp" //*解决方式1，包含cpp源文件

// *解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
#include "person.hpp"

int main()
{
    Person<string, int> p("Tom", 10);
    p.showPerson();
}