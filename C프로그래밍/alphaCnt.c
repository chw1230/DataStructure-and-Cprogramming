/* command-line argument로 공급되는 문자열을 입력 받아 알파벳순으로 빈도수와 함께 출력하는 프로그램 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 100

typedef struct {
    int cnt;
    char str[100];
} Alpha;

int compare_alpha(const void *a, const void *b) {
    return strcmp(((Alpha *)a)->str, ((Alpha *)b)->str);
}

int main(int argc, char *argv[]) {
    Alpha alpha[Max];
    int wordCnt = 0;

    for (int i = 1; i < argc; i++) {
        int found = 0;

        for (int j = 0; j < wordCnt; j++) {
            if (strcmp(alpha[j].str, argv[i]) == 0) {
                alpha[j].cnt++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(alpha[wordCnt].str, argv[i]);
            alpha[wordCnt].cnt = 1;
            wordCnt++;
        }
    }

    qsort(alpha, wordCnt, sizeof(Alpha), compare_alpha);

    for (int i = 0; i < wordCnt; i++) {
        printf("%d %s\n", alpha[i].cnt, alpha[i].str);
    }

    return 0;
}

