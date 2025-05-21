#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	// ncurses 초기화
	initscr();
	noecho();
	cbreak();

	int yMax, xMax;
	getmaxyx(stdscr,yMax,xMax);

	// 새 창 생성
	WINDOW *playwin = newwin(20,50,(yMax /2 ) -10,10);
	box(playwin,0,0);
	refresh();
	wrefresh(playwin);

	// 시작 위치 및 입력 변수
	int xLoc = 1;
	int yLoc = 1;
	int choice;

	// playwin의 크기 재설정
	getmaxyx(playwin, yMax,xMax);

	mvwaddch(playwin,yLoc,xLoc,'@');
	wrefresh(playwin);
	keypad(playwin,true);

	do {
		choice = wgetch(playwin);
지
		switch (choice) {
			case KEY_UP:
				mvwaddch(playwin,yLoc,xLoc,'.');
				// 이전 위치 '.' 이용해서 지우기
				yLoc--;
				if ( yLoc < 1) { // 벗어나는 것을 방
					yLoc = 1;
				}
				break;
			case KEY_LEFT:
				mvwaddch(playwin,yLoc,xLoc,'.');
				xLoc--;
				if (xLoc < 1) {
					xLoc = 1;
				}
				break;
			case KEY_RIGHT:
				mvwaddch(playwin,yLoc,xLoc,'.');
				xLoc++;
				if ( xLoc > xMax -2) {
					xLoc = xMax -2;
				}
				break;
			case KEY_DOWN:
				mvwaddch(playwin,yLoc,xLoc,'.');
				yLoc++;
				if ( yLoc > yMax - 2) {
					yLoc = yMax - 2;
				}
				break;
		}
		mvwaddch(playwin, yLoc,xLoc,'@');
	} while(choice != 'x');
	endwin();
	return 0;
}

