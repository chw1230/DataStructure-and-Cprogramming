#include <ncurses.h>
#include <stdio.h>

int main(void)
{
    int ch;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    ch = getch();

    if (ch == KEY_LEFT)
        printw(" Left arrow is pressed."); // 창에서 좌측이 눌렸다고 글자가 나옴

    refresh();
    getch();
    endwin();

    printf("The key pressed is %d\n", ch); // 다 실행되고 나와서 한줄 출력됨! 입력 값이 아스키 코드로 출력됨

    return 0;
}
