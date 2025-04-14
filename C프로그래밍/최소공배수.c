#include <stdio.h>
/*최소공배수 코드*/

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
    // 두수를 곱한 뒤에 최대공약수로 나누면 두 수의 최소공배수가 나오는 것을 이용!
    printf("%d\n", n1*n2/ gcd(n1, n2));
    return 0;
}
