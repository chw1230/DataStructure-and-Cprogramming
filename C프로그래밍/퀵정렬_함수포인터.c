#include <stdio.h>
#include <string.h>

#define MAXLINE 5000
#define MAXLEN 1000
#define ALLOCSIZE 100000

// char *lineptr[MAXLINE];
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int mygetline(char *, int);
char *alloc(int);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void myqsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

int main(int argc, char *argv[]) {
    int nlines;

    if ( argc > 1 ) { // 데이터가 전달된 경우
	// ./qsortChar 만 입력되어도 atgc는 0임을 고려하여 1로 설정 
        printf("reverse qsort Befoe : \n");
	writelines(argv, argc);
        myqsort(argv, 0, argc - 1);
        printf("\nreverse qsort After : \n");
	writelines(argv, argc);
        return 0;
    } else { // ./qsortChar 뒤에 아무것도 입력되지 않은 경우
        printf("error: argv[]로 전달된 데이터가 없음\n");
        return 1;
    }
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char *p, line[MAXLEN];

    while ((len = mygetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
	    line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines ; i++) {
	    if ( (*(lineptr+i))[0] == '.' ){ 
		// *(lineptr+i) 의미 : argv를 받을 것 이므로 각 인덱스들은 입력한 데이터들의 주소를 값으로 가지고 있음 그 주소들에 접근
		// 주소의 0번째 인덱스가 '.' 인 경우 ./qsortChar의 '.'에  해당되어 출력을 하지 않도록 설정!
		//  그러면 역순이든 아니던 출력을 안하게됨!
		    continue;	  
	   } else {
		  printf("%s\n", lineptr[i]); // 입력한 데이터들을 정상 출력 
	   }
    }
}
void myqsort(char *v[], int left, int right) {
    int i, last;

    if (left >= right) // 종료 조건
        return;

    swap(v, left, (left + right) / 2); // 가운데를 피봇으로 설정 + 가장 좌측으로 옮기기
    last = left; 
    for (i = left + 1; i <= right; i++)
	if (strcmp(v[i], v[left]) >  0) // strcmp(v[i], v[left]) 의 결과에서 0보다 큰경우에만 바꾸도록하여 사전 역순으로 정렬!
            swap(v, ++last, i);

    swap(v, left, last);
    myqsort(v, left, last - 1);
    myqsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int mygetline(char *s, int lim) {
    int c;
    char *start = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - start;
}

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}
