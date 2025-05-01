#include <stdio.h>
#include <string.h>


void writelines(char **, int);        // 문자열 배열 출력 함수
void myqsort(char **, int, int);      // 퀵 정렬(역순) 함수
void swap(char **, int, int);         // 포인터 교환 함수

int main(int argc, char **argv) {
    int n = argc;  
    char **a = argv;

    printf("\nBefore sort.\n");
    writelines(a, n);

    // 알파벳 역순 정렬
    myqsort(a, 0, n - 1);

    printf("\nAfter sort.\n");
    writelines(a, n);

    return 0;
}

// 문자열 배열 출력 함수
void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        // 프로그램 실행 명령어(예: ./2)는 출력하지 않음
        if ((lineptr[i])[0] == '.') continue;

        printf("%s\n", lineptr[i]);
    }
}

// 퀵 정렬 (역순) 함수
void myqsort(char *v[], int left, int right) {
    int i, last;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);  // 중앙값을 피벗으로 선택
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) > 0)  // 역순 정렬을 위한 설정
            swap(v, ++last, i);

    swap(v, left, last);
    myqsort(v, left, last - 1);
    myqsort(v, last + 1, right);
}

// 포인터 교환 함수
void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

