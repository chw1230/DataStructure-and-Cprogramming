#include <stdio.h>

/*
 * 이진 탐색 
 * 배열이 정렬된 뒤에 사용가능함!
 */
int binsearch(int x, int v[], int n) {
	int start, end, mid;

	start = 0;
	end = n -1;
	while(start <= end) {
		mid = (start+end)/2;
		if ( x <v[mid] ) {
			end = mid - 1;
		} else if ( x > v[mid] ) {
			start = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}

