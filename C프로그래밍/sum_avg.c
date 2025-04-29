#include <ctype.h>
#include <stdio.h>

/*문자열을 실수형(double)으로 변환하는 함수*/
#include <ctype.h>
/*문자열을 실수형(double)으로 변환하는 함수*/

double myatof(char s[]) {
	
	double val, power;
	int i, sign;
	
	/* 공백 제거*/
	for (i = 0; isspace(s[i]); i++) 
		;

	/* 부호를 sign에 저장*/
	sign = ( s[i] == '-' )? -1 : 1;
	if ( s[i] == '+' || s[i] == '-'){
		i++; /*부호시작-> 부호저장하고, 건너뛰기(인덱스 증가시켜서)*/	}
	/*isdigit(s[i]) -> 문자가 숫자인경우 아스키 코드를 통해 숫자로 변환*/
	/* 소수점좌측의 문자들을 정수로 만드는 과정*/
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	/* 소수점 나오면 건너뛰기*/
	if ( s[i] == '.') {
		i++;
	}
	/* 조수점 이후의 문자들을 숫자로 만들기 10,100,1000 이렇게 증가*/
	for ( power = 1.0 ;isdigit(s[i]);i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val /power; /* 소수점 좌측을 소수점 우측의 수로 나누어서 처음 입력한 문자열을 소수로 표현하기!!*/
}


int main(int argc ,char *argv[] ){
	double sum = 0;
	double avg = 0;
	int cnt = argc - 1;

	for (int i = 1; i< argc ; i ++){
		sum += myatof(argv[i]);
	}
	avg = sum / cnt;
	printf("sum : %f\n",sum);
	printf("avg : %f\n",avg);
}


