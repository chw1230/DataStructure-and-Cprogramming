#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "tnode.h"

char* mystrdup(char *s) {
	char *p;

	p = (char*)malloc(strlen(s) + 1);
	if (p != NULL){
		strcpy(p,s);
	}
	return p;
}
