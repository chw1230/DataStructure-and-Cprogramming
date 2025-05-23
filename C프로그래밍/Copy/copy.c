#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *readFile, *writeFile; // 읽을 파일과 쓸 파일을 가리키는 포인터 변수들 생성
	char ch; // 문자 복제를 위한 변수 생성하기
	if (argc < 3){
		/* cp 
		 * cp test1.txt
		 * cp test1.txt test2.txt test3.txt 이러한 경우 */
		printf("copy를 하기위해 충분하지 않은 요소로 구성되었음");
		return 1;
	} 
 	/* Copy SOURCE to DEST 의 경우 - cp test1.txt test2.tst */
        // man fopen 해서 보니 fopen(파일, 모드) -> 이런 식으로 사용 , "r" 읽기 모드 "w" 쓰기 모드 
        // 읽어드릴 파일은 "r"로  /  붙여넣을 파일은 "w"로
        readFile = fopen(argv[1],"r"); // 읽어드릴 파일 저장
        writeFile = fopen(argv[2],"w"); // 붙여 넣을 파일 저장

        if ( readFile == NULL ){
                printf("읽어드릴 파일에 오류가 있습니다.");
                return 1;
        }

        if ( writeFile == NULL ){
                printf("붙여 넣을 파일에 오류가 있습니다.");
                fclose(readFile); // 읽어드릴 파일 열린거 닫기
                return 1;
        }

        while (( ch = fgetc(readFile)) != EOF ) {
                fputc(ch, writeFile); // 읽어드릴 파일의 내용을 붙여넣을 파일 붙에 덮어씌우기
        }

        // 파일 닫기
        fclose(readFile);
        fclose(writeFile);

        printf("파일 복사가 완료되었습니다.\n");

        return 0;
}
