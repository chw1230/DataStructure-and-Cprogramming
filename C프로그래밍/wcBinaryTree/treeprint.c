#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "tnode.h"

void treeprint(struct tnode* p) {
	if (p != NULL){
		treeprint(p->left); // 좌측 부터 출력
		printf("%4d %s\n",p->count,p->word);
		treeprint(p->right);
	}
}
