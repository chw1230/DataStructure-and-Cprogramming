#include <stdio.h>
#include <string.h>
#include "key.h"

/*
 * 이진 탐색 
 * 배열이 정렬된 뒤에 사용가능함!
 */

struct key *binsearch(char *word, struct key *tab, int n) {
	struct key* start = &tab[0];
	struct key* end = &tab[n];
	struct key* mid;
	int cond;

	while(start < end) {
		mid = start + (end - start)/2; // 메모리시작값(=low) + (end-start)/2(=(끝값 - 시작 값)%2로 나누고) 그것을 더해주기
		if ( (cond = strcmp(word,mid -> word)) < 0) {
			end  = mid;
		} else if (cond > 0 ) {
			start = mid + 1;
		} else {
			return mid;
		}
	}
	return NULL;
}

