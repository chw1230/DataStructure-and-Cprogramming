/* 선택 정렬
 비교 횟수 -> O(n^2) => 시잔복잡도
 이동 회수 -> 외부 루프의 실행 횟수와 같음 => 3(n-1)
 */

#include <stdio.h>
#define MAX_SIZE 10
#define swap(x,y,t) ( (t) = (x) , (x) = (y), (y) = (t))

void print_list(int list[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void selection_sort(int list[], int n) {
    int tmp;
    for (int i = 0; i < n; i++) {
        int least = i; // i를 가장 작은 값의 인덱스를 의미하는 변수로 설정
        for (int j = i+1; j < n; j++) { // 최소값 찾기/ i다음 인덱스 부터
            if (list[least] > list[j]) {
                least = j; // 가장 작은 값의 인덱스를 의미하는 변수 최신화
            }
        }
        swap(list[least], list[i], tmp);
        print_list(list, n);
    }
}

int main(void)
{
    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE];
    srand(32323);
    for (i = 0; i < n; i++)      // 난수 생성 및 출력 
        list[i] = rand() % 100; // 난수 발생 범위 0~99
    printf("정렬 전: ");
    print_list(list, n);
    selection_sort(list, n);                // 선택정렬 호출 
    printf("정렬 후: ");
    print_list(list, n);
    return 0;
}

