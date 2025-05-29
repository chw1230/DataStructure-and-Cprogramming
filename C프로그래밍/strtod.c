#include <stdio.h>
#include <stdlib.h>

int main(void){
	// atof보다 개선된 함수
	// double strtod(const char *s, char **endp) 
	// 문자열 s를 받아서 결과값으로 double 형의 수를 반환하고 나머지 숫자가 아닌 문자들은 endp로 넘어온 주소에 저장
	char str[] = "3.14159smu.ac.kr";
	char *ptr;
	double value;

	value = strtod(str,&ptr);
	printf("%s, strtod = %f, %s\n",str,value,ptr);
	return 0;
}
