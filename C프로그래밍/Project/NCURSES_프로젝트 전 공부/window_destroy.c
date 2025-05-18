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
    refresh(); getch(); 

    box(my_win, ACS_VLINE, ACS_HLINE); // (창이름 , 세로 구성 요소 , 가로 구성 요소 ) 그냥 문자도 올수 있지만 디자인을 위해서  그래픽 문자로 구성하기! >꼭짓점은 건들 수 없음
    mvwprintw(my_win,0,0,"this is mt box"); // 문제 해결!    
    wrefresh(my_win); getch(); 

    wborder(my_win, '|', '|', '-', '-', '+', '+', '+', '+'); // 모든  원하는 문자로 테두리를 설정할 수 있음! 꼭짓점 변환 가능 
    wrefresh(my_win); getch(); 
    
    wborder(my_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); // 박스 없애기 
    wrefresh(my_win); getch(); 

    delwin(my_win); // 창을 할당 해제하는 것이지 화면에 보이는 박스의 모양을 삭제시켜주지 않음! 그래서 위에서 따로 없애는 작업을 해준 것 

    refresh();
    getch();
    endwin();

    return 0;
}

