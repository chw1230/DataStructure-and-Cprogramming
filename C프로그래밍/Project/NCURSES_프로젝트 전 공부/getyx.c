#include <ncurses.h>

int main(void)
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    int y, x, yb, xb, ym, xm;
    int ch;

    getbegyx(stdscr, yb, xb);
    getmaxyx(stdscr, ym, xm);

    printw("%d, %d, %d, %d\n", yb, xb, ym, xm);

    while ((ch = getch()) != 'q') {
        getyx(stdscr, y, x);
        printw("%d, %d\n", y, x);
        refresh();
    }

    refresh();
    endwin();

    return 0;
}
