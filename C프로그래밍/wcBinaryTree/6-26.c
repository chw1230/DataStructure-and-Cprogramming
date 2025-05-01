#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "tnode.h"

#define MAXWORD 100
struct tnode *addtree(struct tnode * , char *);
void treeprint(struct tnode *);
int getword(char *, int);

int main(void){
	struct tnode *root;
	char word[MAXWORD]; // 단어들을 저장하기 위한 배열

	root = NULL; // 처음에 root 노드를 NULL로 설정
	while (getword(word, MAXWORD) != EOF){
		if (isalpha(word[0])){ // 단어가 나오면 추가
			root = addtree(root, word);
		}
	}
	treeprint(root);
	return 0;
}
