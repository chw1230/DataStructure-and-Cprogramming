#include <stdio.h>
/*유클리드 호제법을 사용하여 최대공약수 구하기*/

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a; // 최대공약수 반환
}

int main(void){
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("%d\n", gcd(n1, n2));
    return 0;
}
