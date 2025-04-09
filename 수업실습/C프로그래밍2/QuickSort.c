#include <stdio.h>
#include <stdlib.h>

// 바꾸기 함수
void swap(int v[],int i,int j){
	int tmp = v[i];
	v[i] = v[j];
	v[j] =tmp;
}

// Quick Sort 함수
void qSort(int v[],int left,int right) {
	
	if (left >= right) {
		// 종료 조건
		return;
	}

	// 가운데 있는 피벗 설정해서 가장 좌측으로 옮기기
	swap(v,left,(left+right)/2);

	int last = left;
	for (int i = left+1 ; i <= right ; i++) {
		if ( v[i] < v[left] ) { // 피벗보다 작은 요소는 바꾸기
			swap(v, i, ++last);
		}
	}
	
	// 정렬한뒤에 피벗 원위치
	swap(v,left,last); // 피벗의 자리에서 좌측은 피벗보다 작은 수, 우측은 피벗보다 큰 수
	qSort(v,left,last-1);
	qSort(v,last+1,right);
}

int main(void) {
	int v[10];
	printf("정렬할 숫자(0~9) 10개를 입력하시오\n");

	for (int i = 0;i<10;i++){
		v[i] = getchar() - '0';
		getchar();
	}

	printf("Quick Sort 이전\n");
	for (int i = 0;i<10;i++){
                printf("%d ",v[i]);
        }
	
	printf("\nQuick Sort 이후\n");
	qSort(v,0,9);
	for (int i = 0;i<10;i++){
                printf("%d ",v[i]);
        }
}
