/*
 * 输入：字符串，这里采用书中坐着自定义的getline函数
 */
#include <stdio.h>
#include <string.h>
#include "simpio.h"

#define MaxWord 1000

static _Bool IsVowel(char ch); // 书中p34, if适用于非此即彼的两种选择(two-way);如果有多个，那么就使用switch。
static void PigLatin(char *word, char buffer[], int bufferSize);

static char *FindFirstVowel(char *word); // *表示函数FindFirstVowel返回一个指向char的指针

int main() {
    char *word;
    char translationBuffer[MaxWord + 1];

    printf("Enter a word: ");
    word = GetLine();
    PigLatin(word, translationBuffer, MaxWord + 1);
    printf("Pig Latin: %s\n", translationBuffer);
}

/*
 * Function:IsVowel
 * Usage: isVowel = IsVowel(character)
 * -----------------------------------
 * 该函数判断字符是否是元音字母，如果是，返回True,否则返回False。
 */
_Bool IsVowel(char ch) {
    switch (ch) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return TRUE;
        default:
            return FALSE;

    }
}

/*
 * Function: PigLatin
 * Usage: PigLatin(word, buffer, bufferSize);
 * ------------------------------------------
 * This function translate a word from English to Pig Latin. The
 * translated word is written into the array buffer, which has an
 * allocated size of bufferSize. The code checks for buffer
 * overflow and generate an error if it occurs.
 */

static void PigLatin(char *word, char buffer[], int bufferSize) {
    char *vp;
    int wordLength;

    vp = FindFirstVowel(word);
    wordLength = strlen(word);
    if (vp == word) {
        wordLength += 3;
    } else if (vp != NULL) {
        wordLength += 2;
    }

    if (wordLength >= bufferSize) {
        Error("Buffer overflow");
    }
    if (vp == NULL) { // 单词中不存在元音字母：不做任何修改
        strcpy(buffer, word);
    } else if (vp == word) { // 单词以元音字母开头： 在单词末尾添加way(示例：any > anyway)
        strcpy(buffer, word);
        strcat(buffer, "way");
    } else {
        // 单词以辅音字母开头: (1)将辅音字母移动到单词尾部，直到第一个字母是元音字母。
        // (2)移动完成后，在单词尾部添加ay(示例：trash > ashtray)
        strcpy(buffer, vp);
        strncat(buffer, word, vp - word);
        strcat(buffer, "ay");
    }
}


/*
 * FindFirstVowel: 找出单词中的第一个元音字母
 */
static char *FindFirstVowel(char *word) {
    char *cp; // 将原来的指针赋值给新的指针，避免原来的指针被修改

    // 遍历指针
    for (cp = word; *cp != '\0'; cp++) { // 注意:在这里*cp表示的是值
        if (IsVowel(*cp)) {
            return cp; // 注意:cp++移动之后，cp指向的地址改变了
        }
    }
    return NULL; // 如果找不到，则返回空指针(NULL)
}

