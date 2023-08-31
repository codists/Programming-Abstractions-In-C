#include <stdio.h>
#include <genlib.h>

/*
 * 1.内存分配和回收的方法：malloc(), free()。 
 * 2.为了解决分配内存的时候判断是否还有足够的内存，引入了方法：GetBlock()，与之相反的方法为FreeBlock(),
 * 位于<genlib.h>
 * 3.dynamic array: NewArray()
 * 
*/

void main() {
    // GetBlock()使用示例
    char *cp;
    cp = GetBlock(10); // 10 bytes

    // 动态数组声明示例
    double *darray;
    darray = NewArray(10, double)
}