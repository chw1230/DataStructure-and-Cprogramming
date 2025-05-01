#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "tnode.h"

struct tnode* talloc(void);
char* mystrdup(char *);

// 노드를 추가해주는 함수
struct tnode* addtree(struct tnode* p, char* w){
	int cond; // 사전적 비교를 진행한뒤에 비교값을 넣을 변수

	if ( p == NULL ) { // 새로운 단어가 들어온 경우
		p = talloc(); // 새로운 노드 만들기
		p -> word = mystrdup(w);
		p -> count = 1;
		p -> left = p -> right = NULL;
	} else if (( cond = strcmp(w,p->word)) == 0) { // 같으면
		p -> count++; // 개수 추가
	} else if ( cond < 0 ){ // 작은 단어면(사전적으로) 
		p -> left = addtree(p->left,w); // 왼쪽에 추가
	} else { // 큰 단어면(사전적으로)
		p -> right = addtree(p->right,w); // 우측에 추가
	}
	return p;
}

