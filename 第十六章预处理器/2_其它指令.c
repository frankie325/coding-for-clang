#include <stdio.h>
#define LIMIT 400
// 移除上面的定义
#undef LIMIT

// * 条件编译，告诉编辑器根据编译时的条件执行或忽略代码块
// #ifdef：如果LIMIT已经定义，则引入limit.h文件
// 可用#if defined (LIMIT)代替
#ifdef LIMIT
#include “limit.h”
#else
#define LIMIT 500
#endif // endif必须存在，不能省略

// #if defined (LIMIT)

// #ifndef：与#ifdef相反，一般用来检查某个宏是否未定义
#ifndef SIZE
#define SIZE 100
#endif

// #if：根据条件判断是否编译代码块
#if SIZE == 100
#undef SIZE
#define SIZE 200
#elif SIZE == 200
#undef SIZE
#define SIZE 300
#else
#undef SIZE
#define SIZE 400
#endif

// #line 指令可以修改行号，文件名等信息
#line 100 // 修改行号为100
#line 100 "test.c" // 修改行号为100，文件名为test.c

// #error 指令用来生成一个错误信息，当编译器遇到#error指令时，会输出错误信息，并停止编译
// #error "Error Message" // 编译时报错

// #pragma 指令是编译器提供的一种机制，用来设置编译器的状态或者行为
// #pragma c9x on // 打开C99支持
// #pragma c9x off // 关闭C99支持
// #pragma comment(lib, "user32.lib") // 链接到user32.lib库
// #pragma warning(disable:4996) // 禁用4996警告
// #pragma warning(error:4996) // 将4996警告转换为错误
#pragma message("Compiling " __FILE__) // 编译时输出消息
// #pragma once // 只编译一次

int main()
{
    // 预定义宏

    // __FILE__：当前文件名
    // __DATE__：当前日期
    // __TIME__：当前时间
    // __LINE__：当前行号
    // __STDC__：是否符合ANSI C标准
    // __STDC_HOSTED__：是否在宿主环境中, 1表示在宿主环境中
    // __STDC_VERSION__：C语言标准版本, C99为199901L, C11为201112L
    printf("File :%s\n", __FILE__);
    printf("Date :%s\n", __DATE__);
    printf("Time :%s\n", __TIME__);
    printf("Line :%d\n", __LINE__);
    printf("ANSI :%d\n", __STDC__);
    printf("ANSI :%d\n", __STDC_HOSTED__);
    printf("ANSI :%ld\n", __STDC_VERSION__);
}
 

