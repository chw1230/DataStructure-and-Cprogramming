/* 이달의 달력을 출력하는 프로그램 */
#include <stdio.h>
#include <time.h>

// 각 달의 날짜 수 (윤년은 따로 처리)
int days_in_month[] = { 31, 28, 31, 30, 31, 30,
                        31, 31, 30, 31, 30, 31 };

// 윤년 판별 함수
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Zeller's Congruence로 1일의 요일 구하기 (0: 일요일 ~ 6: 토요일)
int get_start_day(int year, int month) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (1 + 13*(month + 1)/5 + k + k/4 + j/4 + 5*j) % 7;
    return (h + 6) % 7;
}

int main() {
    // 현재 날짜 가져오기
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    int year = t->tm_year + 1900;  // 연도
    int month = t->tm_mon + 1;     // 월

    // 달력 헤더 출력
    printf("       %d월 %d\n", month, year);
    printf("일 월 화 수 목 금 토\n");

    // 윤년이면 2월 = 29일
    if (is_leap_year(year)) {
        days_in_month[1] = 29;
    }

    int start_day = get_start_day(year, month);   // 1일의 요일
    int days = days_in_month[month - 1];          // 그 달의 일 수

    // 시작 요일 전까지 공백
    for (int i = 0; i < start_day; i++) {
        printf("   ");
    }

    // 날짜 출력
    for (int day = 1; day <= days; day++) {
        printf("%2d ", day);
        if ((start_day + day) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
    return 0;
}

