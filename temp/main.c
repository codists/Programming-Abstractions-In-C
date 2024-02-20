//
// Created by 95232 on 2023/12/2.
//

#include <stdio.h>

#define  C 3
const int a = 1;
#if defined DEBUG

#endif

int add(int a, int b) {
    return a + b + C;
}

int main() {
    const double e = 2.718;
//    int C = 0;
    int a = 3;
    int result;
//    e = 3.1415926;
    printf("C=%d\n", C);
    printf("e=%f\n", e);
    result = add(1, 2);
    printf("result=%d\n", result);
    printf("a=%d\n", a);

    return 0;
}
