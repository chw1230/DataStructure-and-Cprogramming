#include <stdio.h>
#include <stdlib.h>

// 공식 문서에서 요구한 자료형에 맞추기
int compare(const void *p,const void *q){
	int i = *(const int *)p;
	int j = *(const int *)q;

	return (i-j);
}


int compareR(const void *p,const void *q){
        int i = *(const int *)p;
        int j = *(const int *)q;

        return -(i-j);
}


int main(void){
	int a[] = {32,11,97,42,21,70,56,67,88};

	int num = sizeof(a)/sizeof(int);
	printf("%d\n",num); // 길이 출력

	for (int i =0; i<num ;i++){
		printf("%d ",a[i]); // 정렬 전 출력해보기
	}
	
	qsort(a, num,sizeof(int),compare);
        printf("\n오름차순: ");
	for (int i =0; i<num ;i++){
		printf("%d ",a[i]); // 정렬 후  출력해보기
	}
        
	/*
	qsort(a, num,sizeof(int),compareR);
        printf("\n내림차순: ");
	for (int i =0; i<num ;i++){
		printf("%d ",a[i]); // 정렬 후  출력해보기

	}*/

	// 정렬이 되어 있어야 이용 가능!
	int *found; // bsearch를 통해서 반환된 주소를 담을 포인터 변수
	int key = 42;
	if ((found = bsearch(&key,a,num,sizeof(int),compare)) != NULL){
		printf("\nFound key is %d.\n",*found);
	} else {
		printf("\nThere is no %d inList.\n",key);
	}

	key = 13;
	if ((found = bsearch(&key,a,num,sizeof(int),compare)) != NULL){
		printf("\nFound key is %d.\n",*found);
	} else {
		printf("\nThere is no %d inList.\n",key);
	}
	return 0;
}

