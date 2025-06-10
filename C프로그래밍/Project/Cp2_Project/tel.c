#define _XOPEN_SOURCE_EXTENDED
#define _XOPEN_SOURCE
#include <curses.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define START_COL 3 // 원활한 출력을 위한 출력 시작 양식

// 연락처 정보를 저장할 구조체
typedef struct {
    char name[30];   // 이름
    char phone[20];  // 전화번호
    char memo[30];   // 메모
} PhoneEntry;

PhoneEntry *phonebook = NULL;
int size = 100; // 가장 기초 상태일 때의 용량

int entry_cnt = 0;               // 등록된 연락처 수

// 함수 프로토타입
void load_data();
void save_data();
void list_entries(WINDOW *win);
void add_entry(WINDOW *win);
void search_entry(WINDOW *win);
void delete_entry(WINDOW *win);

// 데이터를 파일에서 읽어오는 함수
void load_data() {
    FILE *fp = fopen("data.txt", "r"); // 파일을 읽기 모드로 열기
    if (!fp) return;

    char line[300]; // 한 줄 전체를 저장할 배열

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0'; // 개행 문자 제거

        // ':' 기준으로 분리
        char *name = strtok(line, ":");
        char *phone = strtok(NULL, ":");
        char *memo = strtok(NULL, "\n");

        if (!name || !phone || !memo) continue; // 형식 오류 무시
		
	if (entry_cnt >= size) { // 만약 등록된 연락처 수가 용량보다 크거나 같다면
           size *= 2; // 용량을 2배로 늘려주기
           phonebook = realloc(phonebook, size * sizeof(PhoneEntry));
           if (!phonebook) {
               fprintf(stderr, "메모리 문제 발생\n");
               exit(1);
           }
        }

        strncpy(phonebook[entry_cnt].name, name, sizeof(phonebook[entry_cnt].name));
        strncpy(phonebook[entry_cnt].phone, phone, sizeof(phonebook[entry_cnt].phone));
        strncpy(phonebook[entry_cnt].memo, memo, sizeof(phonebook[entry_cnt].memo));

        entry_cnt++; // 연락처 수 증가
    }

    fclose(fp);
}

// 데이터를 파일에 저장하는 함수
void save_data() {
    FILE *fp = fopen("data.txt", "w"); // 쓰기 모드로 파일 열기 (기존 데이터 삭제됨)
    if (!fp) {
	    return;
    }
    for (int i = 0; i < entry_cnt; i++) {
        fprintf(fp, "%s:%s:%s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].memo);
    }

    fclose(fp);
}

// 연락처 목록 출력하는 함수 (lsit)
void list_entries(WINDOW *win) {
    const int entry_page = 10;  // 한 페이지당 표시할 연락처 수
    int current = 0;            // 현재 페이지 번호
    int total = (entry_cnt + entry_page - 1) / entry_page;

    int ch;
    keypad(win, TRUE); // 방향키 입력 가능

    while (1) {
        werase(win);
        box(win, 0, 0);

        // 제목 및 헤더 출력
        wattron(win, A_BOLD);
        mvwprintw(win, 0, START_COL, "\U0001F4D4 연락처 목록 - Page %d / %d", current + 1, total); // 기능과 현재 있는 페이지를 함께 보여주기
        mvwprintw(win, 2, START_COL, "No.");
        mvwprintw(win, 2, START_COL + 5, "이름");
        mvwprintw(win, 2, START_COL + 35, "번호");
        mvwprintw(win, 2, START_COL + 65, "메모");
        wattroff(win, A_BOLD);

        int start = current * entry_page; // 한 페이지에 출력 되는 시작 번호
        int end = start + entry_page; // 한 페이지에 출력되는 마지막 번호
        if (end > entry_cnt) { // 번호가 총 데이터의 개수를 넘는 경
		end = entry_cnt; // 총 데이터의 개수가 마지막 번호가됨
	}

	// 데이터가 창을 벗어나며 아래로 쭉 출력되지 않도록 하기 위해 페이지네이션 사용
        for (int i = start; i < end; i++) {
            char short_name[21], short_phone[16], short_memo[21];  // 데이터를 잘라서 제공하기 -> dox에 잘 표현 되도록 하기 위해
            strncpy(short_name, phonebook[i].name, 20);
	    short_name[20] = '\0'; // 배열의 끝임을 알 수 있도록 '\0' 넣기
            strncpy(short_phone, phonebook[i].phone, 15);
	    short_phone[15] = '\0';
            strncpy(short_memo, phonebook[i].memo, 20); 
	    short_memo[20] = '\0';
	    mvwprintw(win, (i - start) + 4, START_COL, "%3d. %-25s %-30s %-10s", i + 1, short_name, short_phone, short_memo);
        }

        mvwprintw(win, entry_page + 6, START_COL, " ⏪ 좌/ 우⏩ / 'q' 종료 ");  
        wrefresh(win);

        ch = wgetch(win);
        if (ch == KEY_LEFT && current > 0) { // 좌측 화살 표를 누르면
            current--; // 현재 페이지 줄이기
        } else if (ch == KEY_RIGHT && current < total - 1) { // 
            current++;
        } else if (ch == 'q') {
            break;
        }
    }
}

// 데이터 추가 함수 ( add )
void add_entry(WINDOW *win) {
    werase(win);
    box(win, 0, 0);
    wattron(win, A_BOLD);
    mvwprintw(win, 0, START_COL, "\U0001F64B 새 연락처 추가");
    wattroff(win, A_BOLD);

    char name[100], phone[100], memo[100]; // 입력할 데이터를 잠시 저장할 배열들
    echo();
    mvwprintw(win, 2, START_COL, "이름: ");
    wgetnstr(win, name, sizeof(name));
    mvwprintw(win, 4, START_COL, "번호: ");
    wgetnstr(win, phone, sizeof(phone));
    mvwprintw(win, 6, START_COL, "메모: ");
    wgetnstr(win, memo, sizeof(memo));
    noecho();


    if (entry_cnt >= size) { // 만약 등록된 연락처 수가 용량보다 크거나 같다면
	    size *= 2; // 용량을 2배로 늘려주기
            phonebook = realloc(phonebook, size * sizeof(PhoneEntry));
            if (!phonebook) {
		    fprintf(stderr, "메모리 문제 발생\n");
		    exit(1);
            }
     }

    // 배열에 입력 받은 내용을 구조체 속 각각의 배열에 복사하며 데이터 추가하기
    strncpy(phonebook[entry_cnt].name, name, sizeof(phonebook[entry_cnt].name));
    strncpy(phonebook[entry_cnt].phone, phone, sizeof(phonebook[entry_cnt].phone));
    strncpy(phonebook[entry_cnt].memo, memo, sizeof(phonebook[entry_cnt].memo));
    entry_cnt++; // 총 연락처 개수 증가 시키기

    mvwprintw(win, 8, START_COL, "✅ 추가 완료!");
    wrefresh(win);
    wgetch(win);
}

// 연락처에서 정보를 탐색하는 함수 ( search )
void search_entry(WINDOW *win) {
    char keyword[100]; // 탐색의 기준이 되는 입력된 이름을 담을 배열
    int matched_indices[entry_cnt]; // 탐색에 성공한(=입력과 일치하는) 인덱스를 담을 배열
    int match_cnt = 0; // 입력한 정보와 겹치는 사람들의 수

    werase(win);
    box(win, 0, 0);
    wattron(win, A_BOLD);
    mvwprintw(win, 0, START_COL, "\U0001F50D 연락처 검색");
    wattroff(win, A_BOLD);

    echo();
    mvwprintw(win, 2, START_COL, "검색할 이름: ");
    wgetnstr(win, keyword, sizeof(keyword)); // 이름을 입력 받으며 이름 기반의 탐색 실시
    noecho();

    // 검색 결과 인덱스 저장
    for (int i = 0; i < entry_cnt; i++) {
        if (strstr(phonebook[i].name, keyword)) {
            matched_indices[match_cnt++] = i;
        }
    }

    int current = 0; // 페이지네이션에서 현재 페이지를 의미하는 변수
    int ch;
    keypad(win, TRUE);

    // list 기능에서는 짤린 정보를 제공, 한명한명 볼 수 있는 search기능에서는 연락처 한명을 기준으로 페이지네이션 해서 짤린 정보를 없도록 하기
    // 한 페이지당 입력한 이름을 가지고 있는 사람 한명에 대한 정보 출력하도록 구현
    while (1) {
        werase(win);
        box(win, 0, 0);

        wattron(win, A_BOLD);
        mvwprintw(win, 0, START_COL, "\U0001F50D 검색 결과 - %d 번째 연락처 정보 |  총 %d 명", match_cnt == 0 ? 0 : current + 1, match_cnt);
        wattroff(win, A_BOLD);

        if (match_cnt == 0) { // 0명이면 결과 없음
            wattron(win, A_BOLD);
            mvwprintw(win, 2, START_COL, "\U0001F50D 검색 결과 없음 ❌");
            wattroff(win, A_BOLD);
            wrefresh(win);
            wgetch(win);
            break;
        }

        int idx = matched_indices[current]; // 찾은 정보가 있는 인덱스를 idx에 넘겨주기	
        mvwprintw(win, 3, START_COL , "이름: %s", phonebook[idx].name); // 이름에 대한 정보
        mvwprintw(win, 5, START_COL, "번호: %s", phonebook[idx].phone); // 번호에 대한 정보
        mvwprintw(win, 7, START_COL, "메모: %s", phonebook[idx].memo); // 메모에 대한 정보
        mvwprintw(win, 10, START_COL, "⏪ 좌/우 ⏩ | 'q' 종료");

        wrefresh(win);
        ch = wgetch(win);
        if (ch == KEY_LEFT && current > 0) { // 왼쪽 화살표 누르면
            current--; // 
        } else if (ch == KEY_RIGHT && current < match_cnt - 1) {
            current++;
        } else if (ch == 'q') {
            break;
        }
    }
}

// 연락처에서 삭제하는 함수 ( delete )
void delete_entry(WINDOW *win) {
    // 이름을 통한 삭제를 구현
    char name[100]; // 입력 받은 삭제할 이름을 저장하는 배열
    werase(win);
    box(win, 0, 0);

    wattron(win, A_BOLD);
    mvwprintw(win, 0, START_COL, "\u274C 연락처 삭제");
    wattroff(win, A_BOLD);

    echo();
    mvwprintw(win, 2, START_COL, "삭제할 이름: ");
    wgetnstr(win, name, sizeof(name));
    noecho();

    for (int i = 0; i < entry_cnt; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            // 삭제 대상 정보 미리 출력
            mvwprintw(win, 4, START_COL, "=== 찾은 정보 ===");
            mvwprintw(win, 6, START_COL, "이름: %s", phonebook[i].name);
            mvwprintw(win, 7, START_COL, "번호: %s", phonebook[i].phone);
            mvwprintw(win, 8, START_COL, "메모: %s", phonebook[i].memo);

            // 삭제 여부 확인
            mvwprintw(win, 10, START_COL, "정말 삭제하시겠습니까? (y/n): ");
            wrefresh(win);

            int choice = wgetch(win);
            if (choice == 'y' || choice == 'Y') { // y,Y를 입력한 경우 
                for (int j = i; j < entry_cnt - 1; j++) { // 삭제 대상을 덮어 쓰기 위해  뒤에 있는 정보들을 한칸 씩 땡겨 오기
                    phonebook[j] = phonebook[j + 1];
                }
		entry_cnt--; // 지워진 연락처 정보를 반영하여 연락처 정보 수를 하나 지우기
                wattron(win, A_BOLD);
                mvwprintw(win, 12, START_COL, "\u2705 삭제 완료!");
                wattroff(win, A_BOLD);
            } else { 
                wattron(win, A_BOLD);
                mvwprintw(win, 12, START_COL, "삭제가 취소되었습니다.");
                wattroff(win, A_BOLD);
            }

            wrefresh(win);
            wgetch(win);
            return;
        }
    }

    // 일치하는 이름이 없을 때
    wattron(win, A_BOLD);
    mvwprintw(win, 4, START_COL, "해당 이름 없음\u274C");
    wattroff(win, A_BOLD);
    wrefresh(win);
    wgetch(win);
}






int main() {
    // 디자인을 위한 이모지 사용을 위해서
    setlocale(LC_ALL, "");         // 유니코드 출력(이모지 포함)을 위한 로케일 설정
    initscr();                      // ncurses 초기화
    noecho();                       // 입력값 화면에 표시 안 함
    cbreak();                       // 입력 버퍼 없이 즉시 반영

    int row, col;
    getmaxyx(stdscr, row, col);     // 터미널 크기 가져오기
    WINDOW *menuwin = newwin(10, 40, 1, (col - 40) / 2); // 메뉴 창 생성
    box(menuwin, 0, 0);
    keypad(menuwin, TRUE);         // 방향키 사용 가능
    wrefresh(menuwin);

    // 선택 목록
    char *choices[] = {
        "1.목록 보기",
        "2.추가",
        "3.검색",
        "4.삭제",
        "5.종료"
    };

    int choice;
    int highlight = 0; // 하이라이트 여부를 위한 변수

    phonebook = malloc(size * sizeof(PhoneEntry)); // 초기에 사용할 메오리 할당
    load_data();  // 시작 시 데이터 불러오기

    while (1) {
        werase(menuwin);
        box(menuwin, 0, 0);

        wchar_t title[] = L"\U0001F481연락처 앱\U0001F4DE"; // 전체 제목을 이모지와 함께 표현
        int title_width = wcswidth(title, wcslen(title)); // 유니코드가 포함 된 문자열의 길이를 구하는 함수를 이용하여 제목의 길이 구하기

        wattron(menuwin, A_BOLD);
        mvwprintw(menuwin, 1, (40 - title_width) / 2, "💁연락처 앱📞"); // 제목의 길이를 이용하여 박스의 중앙에 제목 위치 시키기
        wattroff(menuwin, A_BOLD);

        // 메뉴 항목 출력
        for (int i = 0; i < 5; i++) {
		if (i == highlight) {
			wattron(menuwin, A_REVERSE | A_BOLD);
		}
                mvwprintw(menuwin, i + 3, START_COL, "%s", choices[i]);
	
	    	if (i == highlight) {
		       	wattroff(menuwin, A_REVERSE | A_BOLD);
		}
	}
        wrefresh(menuwin);

        choice = wgetch(menuwin);
        switch (choice) { // 01234 를 기반으로 조건 나누기
            case KEY_UP:
                highlight = (highlight == 0) ? 4 : highlight - 1; 
                break;
            case KEY_DOWN:
                highlight = (highlight + 1) % 5;
                break;
            case 10: // Enter key
            {
                WINDOW *actionwin = newwin(20, 90, 12, (col - 90) / 2);
                box(actionwin, 0, 0);

                switch (highlight) {
                    case 0: 
			    list_entries(actionwin); // 0 일때 목록을 보는 함수 실행 (lsit)
			    break;
                    case 1: 
			    add_entry(actionwin); // 1 일때 연락처 추가 함수 실행 (add)
			    break;
                    case 2: 
			    search_entry(actionwin); // 2 일때 연락처 탐색 함수 실행 (search)
			    break;
                    case 3: 
			    delete_entry(actionwin); // 3 일때 연락처 삭제 함수 실해 (delete)
			    break;
                    case 4:
                            save_data();     // 종료 전 저장
                            endwin();        // ncurses 종료
                            return 0;
                }

                delwin(actionwin); // 작업 창 삭제
                break;
            }
        }
    }
}
