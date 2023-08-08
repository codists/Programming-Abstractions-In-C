#include <stdio.h>

void main() {
    int array[5];
    int *p;

    printf("%lu\n", sizeof(array)); //20, int类型占4bytes,5个元素占20个bytes
    printf("%lu\n", sizeof(p)); //8, 64位的电脑

}