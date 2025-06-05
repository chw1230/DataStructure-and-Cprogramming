#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLine 500 
#define MaxInfo 100

// 과일의 정보를 담을 구조체
typedef struct {
	char name[50];
	double price;
	double cnt;
	double sum;
}Info;

// sum을 통한 비교를 위한 함수(오름차순)
int compare_sum(const void * sum1, const void * sum2){
	return ((Info *)sum1)->sum - ((Info *)sum2)->sum;
}


// sum을 통한 비교를 위한 함수(내림차순)
int compare_sum_R(const void * sum1, const void * sum2){
	return -1*(((Info *)sum1)->sum - ((Info *)sum2)->sum );
}

// 과일의 정보 개수
int InfoCnt = 0;

int main(void){
	// 파일을 읽기 형식으로 열기
	FILE *f = fopen("2.txt","r");
	if (!f) {
   		 perror("파일 열기 실패");
	return 1;
	}
	
	Info info[MaxInfo]; // 구조체를 담을 배열 생성
	char line[MaxLine]; // 파일에서 글자를 읽어와 잠시 저장할 배열 생성
	while (fgets(line,sizeof(line),f)) {
		char * p;
		// ":" 형식으로 분리하여 읽기
		char * name = strtok(line,",");
		double price = strtod(strtok(NULL,","),&p);
		double cnt = strtod(strtok(NULL,","),&p);

		// memo에서 "\n"이 나오는 위치를 반환 => 인덱스로 이용하여 널문자 넣기
		//memo[strcspn(memo, "\n")] = 0;

		// 구조체의 값에게 붙여 넣기
		strcpy(info[InfoCnt].name ,name);
		info[InfoCnt].price = price;
		info[InfoCnt].cnt = cnt;
		info[InfoCnt].sum = cnt * price;
	        InfoCnt++;
	}
	fclose(f);

	qsort(info,InfoCnt,sizeof(Info),compare_sum_R);
	printf("단가순\n");
	for (int i =0;i<InfoCnt;i++){
                        printf("%-8s %6.2f %6.2f %7.2f\n",info[i].name,info[i].price,info[i].cnt,info[i].sum);
        }
	return 0;
}
