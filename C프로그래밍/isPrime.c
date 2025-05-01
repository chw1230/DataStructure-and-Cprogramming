#include <stdio.h>


// 소수인지 판별하는 함수
int check_prime(int num) {
    // i는 약수인지 검사하는 변수
    // 제곱근까지 반복 조건 -> 시간 복잡도를 줄이기!
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;  // 나누어 떨어지면 소수가 아님
    }
    return 1;                         // 어떤 수로도 나누어지지 않으면 소수
}

int main() {
    int count = 0;     // 소수 개수 카운트
    int num = 2;       // 검사 시작 숫자 (2부터)

    while (count < 30) {
        if (check_prime(num)) {
            printf("cnt %d : %d \n",count+1, num); // 소수 출력
            count++;
        }
        num++;
    }
    return 0;
}

