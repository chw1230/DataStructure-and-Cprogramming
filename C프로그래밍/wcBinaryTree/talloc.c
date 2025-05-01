#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "tnode.h"

struct tnode* talloc(void) {
	return (struct tnode*) malloc(sizeof(struct tnode)); // 타입을 캐스팅 해서 반환
}
