#include <ncurses.h>

int main(void)
{
    int height, width, start_y, start_x;
    WINDOW *my_win;

    initscr();

    height = 10;
    width = 20;
    start_y = start_x = 10;

    my_win = newwin(height, width, start_y, start_x);
    refresh();
    box(my_win, ACS_VLINE, ACS_HLINE); // (창이름 , 세로 구성 요소 , 가로 구성 요소 ) 그냥 문자도 올수 있지만 디자인을 위해서  그래픽 문자로 구성하기! 꼭짓점은 건들 수 없음
    // wborder(my_win, '|', '|', '-', '-', '+', '+', '+', '+'); // 모든  원하는 문자로 테두리를 설정할 수 있음! 꼭짓점 변환 가능 
    // wprintw(my_win, "this is my box"); 박스의 줄에 글자가 위치하게 됨
    mvwprintw(my_win,1,1,"this is mt box"); // 문제 해결!    
    wrefresh(my_win);

    box(my_win,' ',' '); // 창의 박스에서 꼭짓점만 남음!
    wrefresh(my_win);
    getch();
    endwin();

    return 0;
}

