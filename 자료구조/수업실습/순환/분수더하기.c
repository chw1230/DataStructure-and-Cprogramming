#include <stdio.h>


float sum(int n) {
	if (n == 1) {
		return 1.0;
	}
	else {
		return (1.0 / n) + sum(n - 1);
	}
}

int main(void) {
	printf("%f",sum(15));
}