#include <stdio.h>
#define MAXLINE 1000

int Mygetline(char s[],int lim) {

        int c,i;

        i = 0;
	// 문자들만 입력 받기
        while(--lim > 0 && (c=getchar()) != EOF && c != '\n'){
                s[i++] = c;
        }
        s[i] = '\0';
        return i;
}
	// 문자들을 입력 받아 2진수에서 10진수로 바꾸는 함수
int twoToten(char s[],int len){
	int r = 0;
	int b = 1;
	for ( int i = len-1 ; i > -1 ; i--){
		if ( s[i] == '1' ){
			r = r + (s[i]- '0') *b;
		}
		b *= 2;
	}
	return r;
}

	
int main(void) {
	char s[MAXLINE];

	int len = Mygetline(s,MAXLINE);
	int a  = twoToten(s,len);
	printf("%s\n",s);
	printf("%d\n",a);
	// 16진수로 출력
	printf("%x\n",a);
	// 8진수로 출력
	printf("%o",a);
	return 0;
}
