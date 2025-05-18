#include <ncurses.h>

int main(void)
{
    initscr();

    printw("A Big string which i didn't care to type fully "); // 0,0에서 시작해서 문장입력
    getch();
    mvchgat(0, 0, -1, A_BLINK, 1, NULL); // 커서의 위치를 0,0으로 옮겨서 (0,0) / 그 문장 전체를 (-1) / 속성 주기 (A_BLINK)

    refresh();
    getch();
    endwin();

    return 0;
}
