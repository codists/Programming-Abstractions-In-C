#include <stdio.h>
#define  NJudges 5

int main(int argc, char const *argv[])
{
    // Array declaration p69: type name[size];
    double scores[NJudges]; // 为了方便后续修改，所以数组的大小NElements声明为symbolic constant

    // Array selection p70: array[index]
    scores[0] = 9.2;
    scores[0] = 9.9;
    scores[0] = 9.7;
    scores[0] = 9.0;
    scores[0] = 9.5;

    return 0;
}
