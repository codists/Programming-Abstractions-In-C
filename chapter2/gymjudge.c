//
// Created by qin.xinhui on 2023/7/19.
//
#include <stdio.h>
#include "simpio.h"

#define MaxJudges 100
#define MinScore 0.0
#define MaxScore 10.0


/* Private function prototypes */

static void ReadAllScores(double scores[], int nJudges);

static double GetScore(int judge);

static double Mean(double array[], int n);

/*
 * Function: ReadAllScores
 * Usage: ReadAllScores(scores, nJudges);
 * ---------------------------------------
 * This function reads in scores for each of the judges. The
 * array scores must be declared by the caller and must have
 * an allocated size that is at least as large as nJudges.
 */

static void ReadAllScores(double scores[], int nJudges) { // 数组也是“passed by reference”
    int i;
    for (i = 0; i < nJudges; i++) {
        scores[i] = GetScore(i);
    }
}

/*
 * Function: GetScore
 * Usage: score = GetScore(judge);
 * --------------------------------
 * This function read in the score for the specified judge.
 * The implementation makes sure that the score is in the legal range before returning.
 *
*/
static double GetScore(int judge){
    double score;

    while (TRUE) { // C99使用#include<stdbool.h> while (true) {}，这里保留作者的用法
        printf("Score for judge #%d", judge);
        score = GetReal(); // 这个函数是作者自定义的，位于simpio.c
        if (score >= MinScore && score <= MaxScore) break; // 输入的分数符合要求，跳出循环
        printf("That score is out of range. Try again.\n");
    }
    return score;
}

/*
 * Function: Mean
 * Usage: mean = Mean(array, n)
 * ----------------------------
 * This function returns the statistical mean(average) of a
 * distribution stored in array, which has effective size n.
 */
static double Mean(double array[], int n) {
    int i;
    double total;

    total = 0;
    for (i = 0; i < n; i++) {
        total += array[i];
    }

    return (total / n);
}

void main() {
    double scores[MaxJudges];
    int nJudges; // 实际的数量可以采用输入的方式。每次使用输入需要判断输入的值是否符合要求。

    printf("Enter number of judges: ");
    nJudges = GetInteger();
    if (nJudges > MaxJudges) perror("Too many judges");
    ReadAllScores(scores, nJudges);
    printf("The average score is %.2f\n", Mean(scores, nJudges));
}
