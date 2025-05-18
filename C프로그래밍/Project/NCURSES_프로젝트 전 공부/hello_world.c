#include <ncurses.h>
int main(void)
{
        initscr();                     /* Start curses mode */
        //printw("Hello World !!!");     /* Print w->창을 의미  Hello World , 디폴트 창에 출력하기 */
        
	mvprintw(10,10,"Hello NCURSES World !!!"); // 해당 좌표로 이동해서 출력하기

	refresh();                     /* Print it on to the real screen */
        getch();                       /* Wait for user input */
        endwin();                      /* End curses mode */
        return 0;
} 
