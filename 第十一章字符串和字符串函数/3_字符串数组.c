#include <stdio.h>

int main()
{
    // mytalents是一个内含5个指针的数组，每个指针指向一个字符串字面量的地址
    const char *mytalents[5] = {
        "Adding numbers swiftly",
        "Multiplying accurately",
        "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language"};

    printf("%p\n", mytalents[0]); // 0x100133de0
    mytalents[0] = "hello world"; // 指向了字符串字面量"hello world"的地址
    printf("%p\n", "hello world"); // 0x100133e62
    printf("%p\n", mytalents[0]);  // 0x100133e62

    // yourtalents是一个内含5个数组的数组，每个数组内涵40个char类型的值，存储着字符串字面量的副本
    char yourtalents[5][40] = {
        "Walking in a straight line",
        "Sleeping",
        "Watching television",
        "Reading email",
        "Writing C programs"};

    puts("Let's compare talents.");
    printf("%-36s %-25s\n", "My Talents", "Your Talents");
    for (int i = 0; i < 5; i++)
    {
        printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);
    }
    printf("\nsizeof(mytalents): %zd\n", sizeof(mytalents));   // 40
    printf("sizeof(yourtalents): %zd\n", sizeof(yourtalents)); // 200

    return 0;
}