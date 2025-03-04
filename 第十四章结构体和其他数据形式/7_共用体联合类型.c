#include <stdio.h>

int main()
{
    // 联合里的成员共用同一块内存空间
    union hold
    {
        int digit;
        char letter;
    } h1, h2;

    union hold h;
    printf("%lu \n", sizeof(h)); // 4
    // 成员地址都是一样的
    printf("%p \n", &h);          // 0x16b46b058
    printf("%p \n", &(h.digit));  // 0x16b46b058
    printf("%p \n", &(h.letter)); // 0x16b46b058

    printf("**************\n");
    // *初始化，初始化表只能有一常量
    union hold h3 = {88};          // 初始化联合的digit成员
    union hold h4 = {'c'};         // 初始化联合的letter成员
    union hold h5 = {.digit = 100} // 指定初始化器
    printf("%d\n", h3.digit);
    printf("%c\n", h4.letter);
    printf("**************\n");
    // *引用共用体成员
    h.letter = 'c';
    h.digit = 100;             // 100的ASCII码对应的字符是d
    printf("%c \n", h.letter); // d，因为共用的是同一块内存，所以letter被改变了

    // 应用场景：根据人员身份的不同，设置不同的类型
    struct PeoInfo
    {
        char name[20];
        int num;
        char sex;
        char job;
        // 匿名联合
        union
        {
            int class;     // 如果是学生，则设置为班级
            char position; // 如果是老师，则设置为职位
        } category;        // 分类
    };
    return 0;
}