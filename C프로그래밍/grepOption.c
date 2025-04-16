#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

// option이 있는 grep 구현하기 
// -x : 주어진 패턴이 없는 입력들을 출력
// -n : 라인 넘버와 함께 출력
// 예제 : ./grepOption -x -n the -> 주어진 'the'가 없는 입력을 출력하고 이때 라인 넘버도 함께 출력
// ./grepOption -xn the -> 위와 동일! 

int Mygetline(char *line, int max);

int main(int argc, char *argv[]){
	char line[MAXLINE];
	long lineno = 0; // 몇번 째 줄인지 알려주는 변수
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-') { // 처리할 argc가 남아있고,
	       // (*++argc)[0] == '-' -> 의미 : grep -옵션 에서
	       // (*++argc) 은 -옵션을 의미하고 거기에 0번째 배열이면 '-'를 의미함!
	       // 그러니까 처리할게 남아있고, -를 통해 옵션이 주어진다면 루프를 반복하겠다는 의미!
		while ( c = *++argv[0] ){ // argv는 앞에서의 코드로 인해서 -옵션을 이미 가리키는 상태임!
			// 그래서 argv[0]하면 -를 가리키고, ++하면 -의 다음 옵션을 가리키고
			// *를 통해서 값을 가져오는 것!
			switch (c) {
				case 'x':
					except = 1; // 활성화
					break;
				case 'n':
					number = 1; // 활성화
					break;
				default:
					printf("find : illegal option %c\n",c);
					argc = 0;
					found = -1;
					break;
			}
		}	
	}
	if (argc != 1) {
		// 사용방법이 맞지 않을 때 사용방법을 제시
		printf("Usage : find -x -n pattren\n");
	}
	else {
		while (Mygetline(line,MAXLINE) > 0) {
			lineno++;
			if ((strstr(line,*argv) != NULL) != except) { 
/*1. (strstr(line,*argv) 가 NULL이 아닌 경우 (입력에 패턴이 존재하는 경우) 
 *1.1 (strstr(line,*argv) != NULL) 가 1이다! 
 *1.1.1 except(활성) 1이면 1 != 1 이라서 출력 없음(입력이 패턴에 존재하면 출력 x)
 *1.1.2 except(비활성) 0이면 1 != 0 이라서 -n의 여부 확인으로 넘어감
 *
 *2. (strstr(line,*argv) 가 NULL인 경우 (입력에 패턴이 존재하지 않는 경우)
 *2.1 (strstr(line,*argv) != NULL) 가 0이다!
 *2.1.1 except(활성) 1이면 0 != 1 이라서 -n 여부 확인으로 넘어감
 *2.1.2 except(비활성) 0이면 0 != 0 이라서 입력에 패턴이 존재하지 않지만 -x옵션을 입력하지 않은 경우라 출력이 안되는 상황을 의미함!*/
				if (number) {
					// 옵션 활성화 된다면 줄 같이 찍어주기!
					printf("%ld:",lineno);
				}
				printf("%s",line);
				found++;
			}
		}
	}
	return found;
}


int Mygetline(char s[],int lim) {

        int c,i;

        i = 0;
        while(--lim > 0 && (c=getchar()) != EOF && c != '\n'){
                s[i++] = c;
        }
        if (c == '\n') {
                s[i++] = c;
        }
        s[i] = '\0';
        return i;
}

