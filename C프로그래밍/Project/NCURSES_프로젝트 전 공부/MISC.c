#include <ncurses.h>

int main()
{
    initscr();
    // 그래픽 키워드
    printw("Upper left corner      "); addch(ACS_ULCORNER); printw("\n");
    printw("Upper right corner     "); addch(ACS_URCORNER); printw("\n");
    printw("Lower left corner      "); addch(ACS_LLCORNER); printw("\n");
    printw("Lower right corner     "); addch(ACS_LRCORNER); printw("\n");
    printw("Tee pointing right      "); addch(ACS_LTEE); printw("\n");
    printw("Tee pointing left       "); addch(ACS_RTEE); printw("\n");
    printw("Tee pointing up         "); addch(ACS_BTEE); printw("\n");
    printw("Tee pointing down       "); addch(ACS_TTEE); printw("\n");
    printw("Horizontal line         "); addch(ACS_HLINE); printw("\n");
    printw("Vertical line           "); addch(ACS_VLINE); printw("\n");
    printw("Large Plus or cross over"); addch(ACS_PLUS); printw("\n");
    printw("Scan Line 1             "); addch(ACS_S1); printw("\n");
    printw("Degree Symbol           "); addch(ACS_DEGREE); printw("\n");
    printw("Plus/Minus Symbol       "); addch(ACS_PLMINUS); printw("\n");
    printw("Bullet                  "); addch(ACS_BULLET); printw("\n");
    printw("Arrow Pointing Left     "); addch(ACS_LARROW); printw("\n");
    printw("Arrow Pointing Right    "); addch(ACS_RARROW); printw("\n");
    printw("Arrow Pointing Down     "); addch(ACS_DARROW); printw("\n");
    printw("Arrow Pointing Up       "); addch(ACS_UARROW); printw("\n");
    printw("Less/Equal sign         "); addch(ACS_LEQUAL); printw("\n");
    printw("Greater/Equal sign      "); addch(ACS_GEQUAL); printw("\n");
    printw("Not equal               "); addch(ACS_NEQUAL); printw("\n");

    refresh();
    getch();
    endwin();

    return 0;
}
