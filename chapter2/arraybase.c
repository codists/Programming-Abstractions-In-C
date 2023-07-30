/*
 *
 */
#include <stdio.h>

#define  NJudges 5

int main(int argc, char const *argv[]) {
    /*
     * 1.概念：initializer
     * 2.内存分配：是每个元素的总和
     * 3.字符串数组(character array/the array of character):参考《The C Programming Language》1.9章节
     */
    // initializer
    int digits[5] = {2147483649, 2, 3, 4, 5}; // {1, 2, 3, 4, 5}称为initializer
    // n内存分配
    printf("%lu\n", sizeof(int));  // 4 bytes
    printf("%lu\n", sizeof(digits));  // 20 bytes(因为一个int占4个bytes，所以digits有5个elements,就占20个字节)
    printf("%lu\n", sizeof(digits[0]));  // -2147483647(因为int的最大值是2147483647，所以超范围之后变为负数)
    // 字符数组初始化


    // 遍历数组
    for (int i = 0; i < 5; i++) {
        printf("%d\n", digits[i]);
    }

    // Array declaration p69: type name[size];
    double scores[NJudges]; // 为了方便后续修改，所以数组的大小NElements声明为symbolic constant


    // Array selection p70: array[index]
    scores[0] = 9.2;
    scores[0] = 9.9;
    scores[0] = 9.7;
    scores[0] = 9.0;
    scores[0] = 9.5;

    /*
     * 如何声明字符串数组(how to declare an array of strings)?
     * 1.C语言里面没有string类型，如果要存储string类型的数据，那么使用字符数组(an array of characters)
     * 2.因为字符串是“字符数组”，那么”字符串数组“就是包含“由字符数组构成的数组“，那么怎么声明呢？
     */
    // 1.字符数组
    static char aCity[] = "New York";

    printf(aCity);
//    // 2.
//    static string bigCities[] = { // 如何声明字符串数组(C语言里面没有字符串类型)
//            "New York",
//            "Los Angeles",
//            "Chicago",
//            "Houston",
//            "Philadelphia",
//            "San Diego",
//            "Detroit",
//            "Dallas"
//    };
    return 0;
}
