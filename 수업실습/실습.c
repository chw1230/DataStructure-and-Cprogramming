#include <stdio.h>

struct point
{
	int xpos;
	int ypos;
	struct point* ptr;
};

int main_a(void) {
	struct point pos1 = { 1,1 };
	struct point pos2 = { 2,2 };
	struct point pos3 = { 3,3 };
	pos1.ptr = &pos2;
	pos2.ptr = &pos3;
	pos3.ptr = &pos1;

	printf("pos1.ptr -> ptr -> xpos: %d\n", pos1.ptr->ptr->xpos);
	printf("pos1.ptr -> ptr -> ptr->xpos: %d\n", pos1.ptr-> ptr -> ptr ->xpos);
	printf("pos2.ptr -> ptr -> ptr -> ptr -> xpos: %d", pos2.ptr->ptr->ptr->ptr->xpos);
}