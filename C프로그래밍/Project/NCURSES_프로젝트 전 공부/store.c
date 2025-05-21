#include <ncurses.h>

int main(void) {
	initscr();
	if (!has_colors()) {
		printw("Terminal does not support color.");
	getch();
	return -1;
	}

	start_color(); // 컬러모드 on
	init_pair(1, COLOR_RED, COLOR_WHITE);   // 흰 바탕 빨강 글자
	init_pair(2, COLOR_GREEN, COLOR_WHITE); // 흰 바탕 초록 글자

	attr_t emphasis = A_BLINK | COLOR_PAIR(1);
	attron(emphasis);
	mvaddch(5, 5, 'A');
	mvaddch(5, 7, 'B');
	mvaddch(5, 9, 'C');
	attroff(emphasis);

	chtype c = '@' | COLOR_PAIR(2); // 우측의 속성을 가지는 문자 -> chtype 사용
	mvaddch(7, 5, c);
	getch();    // 화면 유지
    	endwin();   // ncurses 종료
}

