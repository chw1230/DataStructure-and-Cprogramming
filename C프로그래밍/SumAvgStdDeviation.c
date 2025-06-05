/* command-line argument로 공급되는 숫자들의 합과 평균, 표준편차를 구하여 출력하는 프로그램 */
/* gcc -o SumAvgStdDeviation SumAvgStdDeviation.c -lm -> 이렇게 컴파일 하기 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	double sum = 0.0;
	char *p;

	for (int i = 1; i < argc; i++ ){
		//printf("%s ",argv[i]);
		sum += strtod(argv[i],&p);
	}
	double avg = sum / (argc-1);

	// 표준편차를 위한 변수 생성
	double stdev = 0.0;
	for (int i =1; i<= argc-1; i++){ // 값에서 평균을 뺀 값을 제곱해서 합 구하기
		stdev += pow(strtod(argv[i],&p)-avg,2);
	}
	stdev /= (argc - 1); // 합을 데이터 개수로 나누기
	stdev = sqrt(stdev); // 루트 씌우기

	printf("sum: %f\naverage: %f\nstdev: %f",sum,avg,stdev);
	return 0;
}
