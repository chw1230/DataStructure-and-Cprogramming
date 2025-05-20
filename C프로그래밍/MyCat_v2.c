#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *ifp, FILE *ofp);

/* cat 명령어처럼 여러 파일 내용을 연결하여 출력하는 프로그램  ver 2 (표준 입출력,에러 사용 => ver1 ref)*/
int main(int argc, char *argv[ ]) {
	FILE *fp; // 파일 포인터
	void filecopy(FILE *, FILE *); // 파일 복사 함수 선언
	char *prog =argv[0];
	
	if (argc == 1) // cat이후에 아무 것도 입력되지 않은 상태
		filecopy(stdin, stdout); // 표준입력에서 읽은것 표준 출력으로 복사하기
	else
		while ( --argc > 0) { // argc를 하나씩 줄이면서 없어지면 끝내기
			if ((fp = fopen(*++argv, "r") ) == NULL) { // 파일이 존재하지 않는 경우
				// printf("cat: can't open %s\n", *argv);
				fprintf(stderr, "%s: can't open %s\n",prog,*argv); // 표준 에러에 메시지 저장
				exit(1);
			} else {
				filecopy(fp, stdout); // 파일을 열어 내용을 표준 출력으로 복사 
				fclose(fp);
			}
		}
	if ( ferror(stdout)) {
		fprintf(stderr, "%s: errot writing stdout\n",prog); // 표준 에러로 보여주기
		exit(2);
	}
	return 0;
}

// filecopy: 입력 파일 포인터(ifp)에서 출력 파일 포인터(ofp)로 복사
void filecopy(FILE *ifp, FILE *ofp) {
	int c;
	
	while ((c = getc(ifp) ) != EOF)
		putc(c, ofp);
}

/* 실행 예제 
 * 두 개의 파일을 연결 출력 : ./7-27 file1.txt file2.txt
 * 결과 : 
 * Hello from file 1!
 * And this is file 2.
 *
 * 존재하지 않는 파일 포함 : ./7-27 file1.txt missing.txt file2.txt
 * 결과 :
 * Hello from file 1!
 * mycat: can't open missing.txt
 *
 * 입력 없이 실행 : /7-27
 * 결과 :
 * hello world!
 *
 * 에러 리다이렉션 : ./mycat missing.txt 2> error.log
 * 결과 :
 * mycat: can't open missing.txt
*/
