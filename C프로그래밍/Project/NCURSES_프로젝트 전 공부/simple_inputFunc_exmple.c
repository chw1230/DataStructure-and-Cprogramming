#include <ncurses.h>
 #include <string.h> 
int main(void)
{
       	char mesg[]="Enter a string: ";
       	char str[80]; // 내가 입력 할 것이 여기에 들어가용
       	int row,col;
       	initscr();
       	getmaxyx(stdscr,row,col);
       	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
       	
	getstr(str); // getstring
       	mvprintw(LINES -2, 0, "You Entered: %s", str); // print str , LINES는 row와 같은 값을 나타냄
       	refresh();
       	getch();
       	endwin();
       	return 0;
}
