#include <iostream>
using namespace std;
/*
运行前：

    代码区：存放函数体的二进制代码，由操作系统进行管理的
    全局区（静态区）：存放全局变量和静态变量以及常量
    常量区：常量存储在这里，不允许修改

    *​ 全局区还包含了常量区, 全局区的常量区中存放 const修饰的全局常量 和 字符串常量
    * const修饰的局部变量不在全局区；而在栈区

运行后：

    栈区：由编译器自动分配释放, 存放函数的参数值,局部变量等
    堆区：由程序员分配和释放,若程序员不释放,程序结束时由操作系统回收
*/

/*
| 分区            | 存储内容                  | 生命周期         | 管理方式 | 访问权限 |
|-----------------|--------------------------|------------------|----------|----------|
| 栈区（Stack）   | 局部变量、函数参数       | 函数调用期间     | 自动     | 读写     |
| 堆区（Heap）    | 动态分配的内存           | 手动释放前       | 手动     | 读写     |
| 全局/静态区     | 全局变量、静态变量       | 程序运行期间     | 自动     | 读写     |
| 常量区          | 常量、字符串字面量       | 程序运行期间     | 自动     | 只读     |
| 代码区（Text）  | 程序指令（二进制代码）   | 程序运行期间     | 自动     | 只读     |
*/

// 全局区：全局变量
int g_a = 10;
int g_b = 10;

// 全局区：const修饰的全局变量：全局常量
const int c_g_a = 10;
const int c_g_b = 10;

int main()
{
    // 栈区：局部变量
    int a = 10;
    int b = 10;
    cout << "局部变量a地址为： " << (intptr_t)&a << endl; //(int)将地址信息转成10进制
    cout << "局部变量b地址为： " << (intptr_t)&b << endl;

    cout << "全局变量g_a地址为： " << (intptr_t)&g_a << endl;
    cout << "全局变量g_b地址为： " << (intptr_t)&g_b << endl;

    // 全局区：静态变量
    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量s_a地址为： " << (intptr_t)&s_a << endl;
    cout << "静态变量s_b地址为： " << (intptr_t)&s_b << endl;

    // 常量
    // 全局区：字符串常量
    cout << "字符串常量地址为： " << (intptr_t)&"hello world" << endl;
    cout << "字符串常量地址为： " << (intptr_t)&"hello world1" << endl;
    // const修饰的全局变量：全局常量
    cout << "全局常量c_g_a地址为： " << (intptr_t)&c_g_a << endl;
    cout << "全局常量c_g_b地址为： " << (intptr_t)&c_g_b << endl;
    // 栈区：const修饰的局部变量
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "局部常量c_l_a地址为： " << (intptr_t)&c_l_a << endl;
    cout << "局部常量c_l_b地址为： " << (intptr_t)&c_l_b << endl;
}