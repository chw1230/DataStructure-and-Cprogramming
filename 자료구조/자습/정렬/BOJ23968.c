#include <stdio.h>
#define swap(x,y,t) ( (t) = (x) , (x) = (y), (y) = (t))

int main(void) {
	int arr[10001];
	int A, K,tmp,cnt=0;

	scanf("%d %d", &A, &K);

	for (int i = 0; i < A; i++) {
		scanf("%d", &arr[i]);           
	}
	for (int j = A - 1; j > 0; j--) {
		for (int k = 0; k < j; k++) {
			if (arr[k] > arr[k + 1]) {
				cnt++;
				if (cnt == K) {
					printf("%d %d", arr[k + 1], arr[k]);
					return 0;
				}
				swap(arr[k], arr[k + 1], tmp);
			}
		}
	}
	if (cnt < K) {
		printf("%d",-1);
	}
	return 0;
}
