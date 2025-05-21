#include <ncurses.h>

int main(void)
{
    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *inputwin = newwin(3, xMax - 12, yMax - 6, 6);
    box(inputwin, 0, 0);
    refresh();
    wrefresh(inputwin);

    keypad(inputwin, true);

    int ch = wgetch(inputwin);
    if (ch == KEY_UP) { // 위쪽 화살표 누르면 inputwin에 눌렀다고 표현하기!
        mvwprintw(inputwin, 1, 1, "You pressed Up Arrow.");
        wrefresh(inputwin);
    }

    getch();
    endwin();

    return 0;
}

