/*
 *
 */
#include <stdio.h>
#define  NJudges 5

int main(int argc, char const *argv[])
{
    // 概念：initializer
    int digits[5] = {1, 2, 3, 4, 5}; // {1, 2, 3, 4, 5}称为initializer
    printf("test");

    // Array declaration p69: type name[size];
    double scores[NJudges]; // 为了方便后续修改，所以数组的大小NElements声明为symbolic constant

    // Array selection p70: array[index]
    scores[0] = 9.2;
    scores[0] = 9.9;
    scores[0] = 9.7;
    scores[0] = 9.0;
    scores[0] = 9.5;

    static string bigCities[] = { // 如何声明字符串数组(C语言里面没有字符串类型)
        "New York",
        "Los Angeles",
        "Chicago",
        "Houston",
        "Philadelphia",
        "San Diego",
        "Detroit",
        "Dallas"
    };

    return 0;
}
