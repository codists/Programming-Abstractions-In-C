/*
 *
 */
#include <stdio.h>

#define  NJudges 5

/*
 *SumIntegerArray: 数组求和 
*/
int SumIntegerArray(int array[], int n) {
    int i, sum;

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum;

}

void main(int argc, char const *argv[]) {
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

   /*
    * 2.因为string类型经常用到，如何抽象出来进行封装？
    *
    * 
   */ 
//    static string bigCities[] = { // string为自定义数据类型名称，定义在<genlib.h>
//            "New York",
//            "Los Angeles",
//            "Chicago",
//            "Houston",
//            "Philadelphia",
//            "San Diego",
//            "Detroit",
//            "Dallas", // 注意：这里的逗号不是必须的
//    };

    /*
     * 多维数组声明示例: 单位矩阵(identity matrix)
     * 单位矩阵：In linear algebra, the identity matrix of size n is the n x n square matrix with
     * ones on the main diagonal and zeros elsewhere.(见维基百科：https://en.wikipedia.org/wiki/Identity_matrix)
     * 
     */
    static double identityMatrix[3][3] = {
        {1.0, 0.0, 1.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0}
    };
    double weight[] = {1.0, 2.0, 3.0};
    printf("%lu\n", sizeof(weight)); //24, double类型占8bytes,3个元素占24个bytes
    printf("%p\n", &weight); // 0x7ffc2995ab60
    printf("%p\n", &weight[0]); // 0x7ffc2995ab60,a[0]地址就是上一个元素的地址
    printf("%p\n", &weight[1]); // 0x7ffc2995ab68，a[1]比a[0]多8个bytes
    printf("%p\n", &weight[2]); // 0x7ffc2995ab70,a[2]比a[1]多8个bytes，比a[0]多16个bytes

    /*
     *  
     * 
    */
    int result;
    int intList[] = {1, 2, 3, 4, 5}; 
    result = SumIntegerArray(intList, 5);
    printf("数组求和：sum=%d\n", result);
}