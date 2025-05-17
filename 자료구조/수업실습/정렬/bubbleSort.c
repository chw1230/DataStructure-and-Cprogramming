/* 버블 정렬
인접한 2개의 값을 비교하여 순서대로 되어 있지
않으면 서로 교환

 단점 : 데이터의 이동이 많음

 최악의 경우 : 0(n^2) -> 역순으로 정렬되어 있는 경우
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

void bubble_sort(int list[], int n) {
    int tmp;
    for (int i = 0; i < n-1; i++) { // 한 번 돌 때마다 가장 큰 값이 오른쪽으로 정렬됨

        for (int j = 0; j < n-1; j++) { // 앞뒤의 값을 비교하교 바꾸기
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1], tmp);
            }
        }
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
    bubble_sort(list, n);                // 선택정렬 호출 
    printf("정렬 후: ");
    print_list(list, n);
    return 0;

}