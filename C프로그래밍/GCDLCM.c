/*두 정수를 command-line argument로 입력 받고 그 정수들의 최대공약수와 최소공배수를 구해 출력하는 프로그램*/
#include <stdio.h>
#include <stdlib.h>

long gcd(long a, long b) {
    while (b != 0) {
        long tmp = a % b;
        a = b;
        b = tmp;
    }
    return a; // 최대공약수 반환
}

int main(int argc, char *argv[]){
	printf("%s %s\n\n",argv[1],argv[2]);
	//long strtol(const char *s, char **endp, int base)
	long a = strtol(argv[1],NULL,10); // 10진수로 바꾸기
	long b = strtol(argv[2],NULL,10); // 10진수로 바꾸기
	printf("GCD %ld\n",gcd(a,b)); // 최대공약수
	printf("LCM %ld\n",a*b / gcd(a,b)); // 두수의 곱에서 최대공약수를 나누면 최소공배수
	return 0;
}
