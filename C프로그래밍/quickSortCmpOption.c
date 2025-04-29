#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000
#define ALLOCSIZE 100000
#define MAXLINES 5000      /* max #lines to be sorted */
char *lineptr[MAXLINES];   /* pointers to text lines */

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int mygetline(char *, int);
char *alloc(int);
void myqsort(char *lineptr[], int left, int right, int (*comp)(char *, char *));
int numcmp(const char *, const char *);
void swap(char *v[], int i, int j);


/* sort input lines */
int main(int argc, char *argv[])
{
    printf("%d\n\n",argc);
    int nlines;         
    int numeric = 0;    

    if (argc > 1 && strcmp(argv[1], "-n") == 0) // -n 옵션이 입력되면 숫자 비교 활성화
        numeric = 1;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
            printf("qsort Befoe : \n");
            writelines(lineptr, nlines);
	    myqsort((char **) lineptr, 0, nlines - 1, (int (*)(char *, char *))(numeric ? numcmp : strcmp) );
        
	    printf("\nqsort After : \n");
            writelines(lineptr, nlines);
            return 0;
    } else {
            printf("input too big to sort\n");
            return 1;
    }
}


void myqsort(char *v[], int left, int right, int (*comp)(char *, char *) )
{
    int i, last;

    if (left >= right) 
        return;

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);
    myqsort(v, left, last - 1, comp);
    myqsort(v, last + 1, right, comp);
}

// 숫자를 활용한 비교
int numcmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
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
