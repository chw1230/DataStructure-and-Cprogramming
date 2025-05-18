 #include <ncurses.h>
 #include <string.h> 
int main(void) 
{
       	char mesg[]="Just a string";
       	int row,col;
       	initscr();
       	getmaxyx(stdscr,row,col); /* get the number of rows and columns */
       	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg); // 화면 정중앙에 찍도록  x좌표 설정하기!
       	/* print the message at the center of the screen */
       
	mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
       	printw("Try resizing your window(if possible) and then run this program again");
       	refresh();
	getch();
	endwin();
        return 0;
}
