#include <stdio.h>
#define BUFSIZE 100

extern char buf[BUFSIZE];
extern int bufp;

void ungetch(int c) {
	if (c == EOF) return;
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buf[bufp++] = c;
	}
}
