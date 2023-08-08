#include <stdio.h>

int SumIntegerArray(int array[], int n);
int SumIntegerArray2(int *array, int n);

/*
 * SumIntegerArray:数组求和，数组用法
*/
int SumIntegerArray(int array[], int n) {
    int i, sum;

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum;

}

/*
 * SumIntegerArray2：数组求和指针用法
*/
int SumIntegerArray2(int *ip, int n) {
    int i, sum;

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += *ip++;
    }
    return sum;

}
void main() {
    int aSum, pSum;
    int array[] = {1, 2, 3, 4, 5};

    aSum = SumIntegerArray(array, 5);
    printf("对数组[1, 2, 3, 4, 5]求和: aSum=%d\n", aSum);

    pSum = SumIntegerArray2(array, 5);
    printf("对数组[1, 2, 3, 4, 5]求和: pSum=%d\n", aSum);
}