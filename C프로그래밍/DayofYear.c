#include <stdio.h>

static char daytab[2][13] = { // 윤년인 달과 아닌 달 
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

// 주어진 날짜가 그 해의 몇 번째 날인지 계산하는 함수
int day_of_year(int year, int month, int day){
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; // 윤년이면 1 아니면 0 들어감
	for (i = 1; i < month ; i++){ 
		day += daytab[leap][i]; // 한달을 구성하는 날짜들을 더해서 몇 번째 날인지 구하기
	}
	return day;
}

// 매개변수로 주어진 n번째 날이 몇 월 며칠인인지 알려주는 함수
void month_day(int year, int yearday, int * pmonth, int * pday){
	int i, leap;

	leap = year % 4 && year % 100 != 0 || year % 400 == 0; // 윤년이면 leap에 1이 들어가게됨 아니면 0이 들어감
	for (i = 1; yearday > daytab[leap][i]; i++){ // 한달 보다 큰 경우에만 돌리기
		yearday -= daytab[leap][i]; // 주어진 날을 한달을 구성하는 일수 로 빼기
	}
	*pmonth = i; // 반복된 횟수가 달을 의미
	*pday = yearday; // 한달을 구성하는 일 수 보다 작은 일 수가 들어감!
}


int main(void){

	int day = day_of_year(2020,4,20);
	printf("%d\n",day);

	int month;
	month_day(2020,111,&month,&day);
	printf("%d, %d\n",month,day);
	return 0;
}
