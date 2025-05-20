#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ... )
{
	// 고정된 인자 귀에 가변 인자 몇개든 받을 수 있음

	va_list ap; /* 가변 인자를 처리하기 위한 변수*/
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt); /*ap를 첫 번째 가변 인자를 가리키도록 초기화*/
	for (p = fmt; *p; p++) { // 포맷 문자열을 한 글자씩 검사
		if (*p != '%' ) { 
			putchar(*p);
			continue;
		}
		switch (*++p) { // 다음에 오는 형식 지정자를 확인, 인자를 꺼냄
		case 'd':
			ival = va_arg(ap, int); // ap에 저장된 것을 자료형에 맞게 뽑기
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap); // 가변인자 처리를 끝내고 정리
}

int main(void){
	minprintf("ind : %d, double : %f, String :%s\n", 1, 2.1, "Hello");
	return 0;
}
