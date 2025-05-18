#include <ncurses.h>
#include <stdlib.h>

int main(void)
{
    initscr();                 // Start curses mode
    printw("Hello World !!!\n"); // Print Hello World
    refresh();
    getch();

    def_prog_mode();           // Save the tty modes
    endwin();                  // End curses mode temporarily
    system("/bin/bash");       // Do whatever you like in cooked mode

    reset_prog_mode();         // Return to the previous tty mode stored
    refresh();                 // Do refresh() to restore the Screen contents
    printw("Another String\n"); // Back to curses
    refresh();
    getch();

    endwin();                  // End curses mode

    return 0;
}
