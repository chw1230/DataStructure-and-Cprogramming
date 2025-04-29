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
void myqsort(char *lineptr[], int left, int right, int reverse);
void swap(char *v[], int i, int j);

int main(int argc, char *argv[]) {
    int nlines;
    int reverse = 0;
    int c;
    while (--argc > 0 && (*++argv)[0] == '-') { // 처리할 argc가 남아있고,
	       // (*++argc)[0] == '-' -> 의미 : grep -옵션 에서
	       // (*++argc) 은 -옵션을 의미하고 거기에 0번째 배열이면 '-'를 의미함!
	       // 그러니까 처리할게 남아있고, -를 통해 옵션이 주어진다면 루프를 반복하겠다는 의미!
		while ( c = *++argv[0] ){ // argv는 앞에서의 코드로 인해서 -옵션을 이미 가리키는 상태임!
			// 그래서 argv[0]하면 -를 가리키고, ++하면 -의 다음 옵션을 가리키고
			// *를 통해서 값을 가져오는 것!
			switch (c) {
				case 'r':
					reverse = 1; // 활성화
					break;
				default:
					printf("find : illegal option %c\n",c);
					argc = 0;
					break;
			}
		}	
    }
    if ( argc > 1 ) { // 데이터가 전달된 경우
	// ./qsortChar 만 입력되어도 atgc는 0임을 고려하여 1로 설정 
        printf("reverse qsort Befoe : \n");
	writelines(argv, argc);
        myqsort(argv, 0, argc - 1,reverse);
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

void myqsort(char *v[], int left, int right,int reverse) {
    int i, last;

    if (left >= right) // 종료 조건
        return;

    swap(v, left, (left + right) / 2); // 가운데를 피봇으로 설정 + 가장 좌측으로 옮기기
    last = left; 
    for (i = left + 1; i <= right; i++)
	    if ( reverse == 1) {
		    if (strcmp(v[i], v[left]) >  0) // strcmp(v[i], v[left]) 의 결과에서 0보다 큰경우에만 바꾸도록하여 사전 역순으로 정렬!
   		   		 swap(v, ++last, i);
	    } 
   	    else { 
		   if (strcmp(v[i], v[left]) <  0) // strcmp(v[i], v[left]) 의 결과에서 0보다 작은경우에만 바꾸도록하여 사전순으로 정렬!
                                 swap(v, ++last, i);
	    }

    swap(v, left, last);
    myqsort(v, left, last - 1,reverse);
    myqsort(v, last + 1, right,reverse);
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
