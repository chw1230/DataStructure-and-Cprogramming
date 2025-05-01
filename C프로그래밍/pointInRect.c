#include <stdio.h>
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

typedef struct { // 점을 의미하는 구조체
	int x;
	int y;
} Point;

typedef struct { // 사각형을 의미하는 구조체
	Point pt1;
	Point pt2;
} Rect;

// 함수 프로토타입 선언
Point makePoint(int, int);
Point addPoint(Point, Point);
void printPoint(Point);
Rect canonRect(Rect);
int ptInRect(Point, Rect);



int main(void) {
	int x1 = 1, y1 = 4;
	int x2 = 8, y2 = 8;

	// point 생성
	Point p1 = makePoint(x1,y1);
	Point p2 = makePoint(x2,y2);
	/* 동일한 의미
	 * Point p1 = {1,4}; 
	 * Point p2 = {8,8};*/
	printf("p1의 좌표");
	printPoint(p1);
	printf("p2의 좌표");
	printPoint(p2);
	printf("\n-------------------------\n\n");

	// 좌표의 덧셈
	// addpoint 함수 이용하기!
	Point sumP = addPoint(p1,p2);
	printf("p1 + p2의 좌표");
	printPoint(sumP);
	printf("\n-------------------------\n\n");

	// rect 생성
	Rect r = {p2,p1}; // 좌표의 크기를 고려하지 않고 그냥 좌표를 부여
	printf("r의 pt1 좌표");
	printPoint(r.pt1);
        printf("r의 pt2의 좌표");
        printPoint(r.pt2);
	printf("\n-------------------------\n\n");

	// rect 정규화하기
	printf("정규화\n");
	r = canonRect(r);
	printf("r의 pt1 좌표");
        printPoint(r.pt1);
        printf("r의 pt2의 좌표");
        printPoint(r.pt2);
	printf("\n-------------------------\n\n");

	// 점이 사각형 안에 포함되는지 확인하기
	int check;
	Point exP = {5,5};
	printPoint(exP);
	check = ptInRect(exP,r);
	if (check) {
		printf("점이 사각형안에 있습니다.");
	}
	else {
		printf("점이 사각형 안에 없습니다.");
	}
	printf("\n-------------------------\n\n");
	
	// 포인터를 통해서 값 출력하기
	printf("\np1을 가리키는 포인터를 통해서 값 출력하기\n");	
	Point *pp;
	pp = &p1;
	printf("(%d,%d)",pp->x,pp->y); // (*pp).x 와 동일함
	
	printf("\nr(사각형)을 가리키는 포인터를 통해서 값을 출력하기\n");
	Rect *rp;
	rp = &r;
	printf("r의 p1의 x : %d\n",rp->pt1.x); // 동일한 형태 r.pt1.x , rp->pt1.x , (r.pt1)->x , (rp->pt1).x
	printf("r의 p1의 y : %d",rp->pt1.y); // 동일한 형태 r.pt1.y , rp->pt1.y , (r.pt1)->y , (rp->pt1).x
}

Point makePoint(int x, int y){
	Point tmp;

	tmp.x = x;
	tmp.y = y;
	return tmp;
}

Point addPoint(Point p1, Point p2){
	Point tmp; // p1의 기존 값 유지하기 위해 tmp 생성!
	tmp.x = p1.x + p2.x;
	tmp.y = p1.y + p2.y;

	return tmp;
}

void printPoint(Point p){
	printf("(x,y) = (%d,%d)\n", p.x ,p.y);
}

Rect canonRect(Rect r){ // 좌표 2개의 입력된 사각형의 두 꼭짓점이 어떤 순서든지 간에, 좌측 하단 → 우측 상단”으로 재배열하여 정상적인 방향의 사각형으로 정리해주는 함수
	Rect tmp;	
	tmp.pt1.x = min(r.pt1.x , r.pt2.x);
	tmp.pt1.y = min(r.pt1.y , r.pt2.y);
	tmp.pt2.x = max(r.pt1.x , r.pt2.x);
	tmp.pt2.y = max(r.pt1.y , r.pt2.y);
	return tmp;
}

int ptInRect(Point p, Rect r){
	return (p.x >= r.pt1.x) && (p.x < r.pt2.x) && (p.y >= r.pt1.y) && (p.y < r.pt2.y);
}
