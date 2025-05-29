#include <stdio.h>

// gap만큼 떨어진 부분 리스트들에 대해 삽입 정렬을 수행
void inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i <= last; i += gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
			list[j + gap] = list[j]; // 큰 값을 뒤쪽으로 저장
		}
		list[j + gap] = key; // key에 저장한 작은 값을 저장하기
	}
}

void shell_sort(int list[], int n) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap /= 2) { // gap 절반 줄이기
		if ((gap % 2) == 0) 
			gap++;  // gap이 짝수일 경우 홀수로 만들어주는 코드

		for (i = 0; i < gap; i++) { // 시작 인덱스를 키워가며 함수 호출하기 
			inc_insertion_sort(list, i, n - 1, gap);
		}
			
	}
	for (int k = 0; k < n; k++) {
		printf("%d ", list[k]);
	}
	printf("\n");
}

int main() {
	int list[] = { 45, 23, 53, 12, 90, 17, 65, 30 };
	int n = sizeof(list) / sizeof(list[0]);

	printf("정렬 전 배열: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	printf("정렬 후 배열: ");
	shell_sort(list, n);

	return 0;
}
