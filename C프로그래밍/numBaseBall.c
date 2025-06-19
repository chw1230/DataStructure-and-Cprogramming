#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 시험 후 리펙토링
int main(void) {
	srand((unsigned int)time(NULL));

	int arr[3] = { -1,-1,-1 }; // 초기화
	int count = 0;

	while (count < 3) {
		int r = rand() % 10;
		int isDuplicate = 0;

		for (int i = 0; i < count; i++) {
			if (arr[i] == r) {
				isDuplicate = 1;
				break;
			}
		}

		if (!isDuplicate) {
			arr[count++] = r;
		}
	}


	for (int i = 0; i < 3; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
