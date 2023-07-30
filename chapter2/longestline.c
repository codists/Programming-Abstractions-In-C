#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);

void copy(char to[], char from[]);

/* print the longest input line */
int main() {
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}

/* 读取输入的字符然后存入到数组中，并返回该数组的长度*/
int getline(char s[], int lim) {
    int c, i; // c: 输入的字符。i: 行数。
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c; // 换行符也需要加入到存入数组
        ++i; // 如果输入的是换行符，那么行数加1
    }
    s[i] = '\0'; // 输入结束，最后一个字符为0
    return i; // 返回行的长度
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
