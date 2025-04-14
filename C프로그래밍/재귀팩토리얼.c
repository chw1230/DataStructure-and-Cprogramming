#include <stdio.h>

long fac(int n) {
	if ( n == 1){
		return 1;
	}
	else {
		return n * fac(n-1);
	}
}


int main(void) {
	for (int i = 1; i<=20; i++){
		printf("%ld\n",fac(i));
	}
}
