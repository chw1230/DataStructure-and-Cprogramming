/* 삽입 정렬
 정렬이 안된 리스트 중 가장 앞에 있는 것을 정렬이 된 리스트에서 들어갈 자리 찾아 삽입

 단점 : 데이터의 이동이 많음

 최선의 경우 : O(n) -> 이미 정렬된 경우
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

void insertion_sort(int list[], int n) {
    int key,j;
    for (int i = 1; i < n; i++) { 
        key = list[i]; // 옮기고자 하는 값을 key에 저장해두기
        for (j = i - 1; j > -1 && list[j] > key; j--) {
            list[j + 1] = list[j];  // 값의 우측으로의 이동
        }

        list[j + 1] = key; // 반복문에서 마지막에 j-- 때문에 하나 작아 지므로 +1 해주기! 
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
    insertion_sort(list, n);                // 선택정렬 호출 
    printf("정렬 후: ");
    print_list(list, n);
    return 0;
}

