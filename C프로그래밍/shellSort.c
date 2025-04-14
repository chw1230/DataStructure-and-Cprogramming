#include <stdio.h>

void shellsort(int a[], int l)
{
	int gap;
	int tmp = 0; // tmp를 통한 값의 변경
	for ( gap = l/2; gap>0 ; gap /= 2){ // gap을 2로 나눠주는 반복문
		for( int i = gap ; i < l ; i++ ) { // gap만큼의 인덱스 차이를 가진 세트(좌측,우측)들의 값을 비교하기 위한 반복문
			for ( int j = i - gap ; 0 <= j && a[j] > a[j+gap] ; j=j-gap ) { // 바꾼 값에서 gap 만큼 작은 인덱스에 있는 값과 비교하는 반복문
				// i와 gap의 차이가 0보다 커야하고, 앞에 있는 값이 더 큰 경우 바꾸기
				// 그리고 j의 값은 또 gap 만큼 작는 인덱스와 비교하게 하기 위해 gap 만큼을 빼주기
				tmp = a[j];
				a[j] = a[j+gap];
				a[j+gap] = tmp;		
			}
		}
	}
}

int main(void)
{
	int a[] = {9, 6, 10, 4, 2, 3, 1, 7, 11};
	int i;
        int l = sizeof(a) / sizeof(int); //배열의 길이

   	printf("Before sort\n");
        for (i = 0; i < l; ++i){
		printf("%4d", a[i]);
	}
		putchar('\n');


	shellsort(a, l);
	printf("After sort\n");
	for (i = 0; i < l; ++i){
		printf("%4d", a[i]);
	}
		putchar('\n');
	return 0;
}

