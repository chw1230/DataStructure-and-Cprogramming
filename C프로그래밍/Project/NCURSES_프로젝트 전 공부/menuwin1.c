#include <ncurses.h>

int main(void)
{
    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menuwin = newwin(6, xMax - 12, yMax - 8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    keypad(menuwin, true);

    char *choices[3] = {"Walk", "Jog", "Run"};
    int choice;
    int highlight = 0;

    while (1) {
        for (int i = 0; i < 3; i++) {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }

        choice = wgetch(menuwin);

        switch (choice) {
    // 하이라이트가 0이되거나 4가 되면 글자에서 벗어나는 문제 발생을 막기위해서 조건문 사용
            case KEY_UP:
                highlight--;
                if (highlight < 0) highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight > 2) highlight = 2;
                break;
            default:
                break;
        }
	if (choice == 10){
		break;
	}
    }

    printw("Your choice is: %s", choices[highlight]);
    getch();
    endwin();
    return 0;
}

