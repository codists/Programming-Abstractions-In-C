/*
 * File: quadeq.c
 * --------------
 * This program finds roots of the quadratic equation
 *  
 * ax^2 + bx + c = 0
 *  问题：
 * 1.如何获取输入的值？
*/
#include <math.h>
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/*
 * 函数原型(Private function prototype)
*/
static void GetCoefficients(double *pa, double *pb, double *pc);
static void SolveQuadratic(double a, double b, double c, double *px1, double *px2);
static void DisplayRoots(double x1, double x2);

/*

*/
void GetCoefficients(double *pa, double *pb, double *pc) {
    printf("Enter coefficients of quadratic equation:\n");
    /*
     *1.一次性全部输入还是逐个输入？ 答：逐个输入。
     *2.因为a, b, c还要给下一个函数使用，所以传递的是指针(引用传递)。
     *
    */
    printf("请输入第1个系数a:\n");
    scanf("%lf", pa);
    printf("请输入第2个系数b:\n");
    scanf("%lf", pb);
    printf("请输入第3个系数c:\n");
    scanf("%lf", pc);
}

static void SolveQuadratic(double a, double b, double c, double *px1, double *px2) {
    /*
     *1.如何解一元二次方程？答：求根公式,x=(-b ± √(b^2-4ac))/2a。
     *2.数学运算：(1)求根？sqrt();(2)求幂？pow()。
     *3.因为a, b, c没有涉及到修改，所以值传递，而x1, x2, 计算出来还要返回给一个函数使用，所以采用
     *应用传递。
     *4.特殊情况处理：(1)a==0,此时不是一元二次方程。(2)b^2-4ac<0,此时误解。
     *5.特殊情况怎么处理？答：使用Error方法报错。
     * 
    */
    double disc, sqrtDisc; // disc: discriminant:判别式(即b^2-4*a*c)
    if (a == 0) {
        // 书中这里用的是Error，但是编译不通过，提示：undefined reference to `Error'，改用prror
        // Error("a不能等于0"); 
        perror("a不能等于0");

    }
    // 原书使用的是b * b表示 b^2
    disc = pow(b, 2) - 4 * a *c;
    if (disc < 0) {
        perror("根是复数");
    }  
    sqrtDisc = sqrt(disc);
    *px1 = (-b + sqrtDisc)/ (2 * a);
    *px2 = (-b - sqrtDisc)/ (2 * a);
}

/*
 *Function: DisplayRoots
 *Usage: DisplayRoots(x1, x2) 
 * --------------------------
 * This function displays the value x1 and x2, which are the roots of a quadratic equation
 * %g:如果未指定精度，则是6位，参考：https://stackoverflow.com/questions/54162152/what-precisely-does-the-g-printf-specifier-mean
*/
static void DisplayRoots(double x1, double x2) {
    // printf("方程的解是x1=%lf, x2=%lf", x1, x2);
    if (x1 == x2) {
        printf("There is a double root at %g\n", x1);
    } else {
        printf("The root are %g and %g\n", x1, x2);
    }
}

/*
 * 测试方程1：2x^2-4x+2=0,根为1.
 * 测试方程2：2x^2+4x-2=0,根为2
 * 
*/
void main() {
    double a, b, c, x1, x2;

    GetCoefficients(&a, &b, &c);
    SolveQuadratic(a, b, c, &x1, &x2);
    DisplayRoots(x1, x2);

}