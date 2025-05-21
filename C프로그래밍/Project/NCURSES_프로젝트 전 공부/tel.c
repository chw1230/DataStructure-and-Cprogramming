#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[30];
    char phone[20];
    char memo[50];
} PhoneEntry;

PhoneEntry phonebook[MAX_ENTRIES];
int entry_count = 0;

void load_data() {
    FILE *fp = fopen("data.txt", "r");
    if (!fp) return;

    while (fscanf(fp, "%[^:]:%[^:]:%[^\n]\n",
                  phonebook[entry_count].name,
                  phonebook[entry_count].phone,
                  phonebook[entry_count].memo) == 3) {
        entry_count++;
    }

    fclose(fp);
}

void save_data() {
    FILE *fp = fopen("data.txt", "w");
    if (!fp) return;

    for (int i = 0; i < entry_count; i++) {
        fprintf(fp, "%s:%s:%s\n",
                phonebook[i].name,
                phonebook[i].phone,
                phonebook[i].memo);
    }

    fclose(fp);
}

void list_entries(WINDOW *win) {
    werase(win);
    box(win, 0, 0);
    for (int i = 0; i < entry_count; i++) {
        mvwprintw(win, i+1, 1, "%d. %s | %s | %s", i + 1,
                  phonebook[i].name, phonebook[i].phone, phonebook[i].memo);
    }
    wrefresh(win);
    wgetch(win);
}

void add_entry(WINDOW *win) {
    char name[30], phone[20], memo[50];
    echo();

    mvwprintw(win, 1, 1, "이름: ");
    wgetnstr(win, name, sizeof(name));
    mvwprintw(win, 2, 1, "번호: ");
    wgetnstr(win, phone, sizeof(phone));
    mvwprintw(win, 3, 1, "메모: ");
    wgetnstr(win, memo, sizeof(memo));

    strcpy(phonebook[entry_count].name, name);
    strcpy(phonebook[entry_count].phone, phone);
    strcpy(phonebook[entry_count].memo, memo);
    entry_count++;
    noecho();

    mvwprintw(win, 5, 1, "추가 완료!");
    wrefresh(win);
    wgetch(win);
}

void search_entry(WINDOW *win) {
    char keyword[30];
    echo();
    mvwprintw(win, 1, 1, "검색할 이름: ");
    wgetnstr(win, keyword, sizeof(keyword));
    noecho();

    werase(win);
    box(win, 0, 0);
    int found = 0;
    for (int i = 0; i < entry_count; i++) {
        if (strstr(phonebook[i].name, keyword)) {
            mvwprintw(win, ++found, 1, "%s | %s | %s",
                      phonebook[i].name,
                      phonebook[i].phone,
                      phonebook[i].memo);
        }
    }

    if (found == 0)
        mvwprintw(win, 1, 1, "검색 결과 없음.");

    wrefresh(win);
    wgetch(win);
}

void delete_entry(WINDOW *win) {
    char name[30];
    echo();
    mvwprintw(win, 1, 1, "삭제할 이름: ");
    wgetnstr(win, name, sizeof(name));
    noecho();

    for (int i = 0; i < entry_count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            for (int j = i; j < entry_count - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            entry_count--;
            mvwprintw(win, 3, 1, "삭제 완료!");
            wrefresh(win);
            wgetch(win);
            return;
        }
    }

    mvwprintw(win, 3, 1, "해당 이름 없음.");
    wrefresh(win);
    wgetch(win);
}

int main() {
    initscr();
    noecho();
    cbreak();

    WINDOW *menuwin = newwin(10, 40, 1, 1);
    box(menuwin, 0, 0);
    keypad(menuwin, TRUE);

    char *choices[] = {
    	 "1. List",
   	 "2. Add",
   	 "3. Search",
   	 "4. Delete",
   	 "5. Exit"
    };
    int choice;
    int highlight = 0;

    load_data();

    while (1) {
        werase(menuwin);
        box(menuwin, 0, 0);
        for (int i = 0; i < 5; i++) {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        wrefresh(menuwin);

        choice = wgetch(menuwin);
        switch (choice) {
            case KEY_UP:
                highlight = (highlight == 0) ? 4 : highlight - 1;
                break;
            case KEY_DOWN:
                highlight = (highlight + 1) % 5;
                break;
            case 10: // Enter key
                {
                    WINDOW *actionwin = newwin(15, 50, 12, 1);
                    box(actionwin, 0, 0);
                    switch (highlight) {
                        case 0: list_entries(actionwin); break;
                        case 1: add_entry(actionwin); break;
                        case 2: search_entry(actionwin); break;
                        case 3: delete_entry(actionwin); break;
                        case 4:
                            save_data();
                            endwin();
                            return 0;
                    }
                    delwin(actionwin);
                }
                break;
        }
    }
}

