#include <stdio.h>

#define IN 1
#define OUT 0

void main(void) {
        int c,nl,nw,nc,state;

        state = OUT;
       	// 단어의 개수를 정할 때 필요한 변수를 의미
	// state가 out이면 단어 인식 범위 밖에 있는 것이고, in 단어 인식 범위 안에 있는 것임
       
       	nl = nw = nc =0; // 문장, 단어, 글자들의 개수를 의미하는 변수 0으로 설정
        while((c=getchar()) != EOF) { // EOF 입력하면 종료
                ++nc; // 글자 개수 늘리기
                if (c == '\n') // \n 입력되면 문장으로 인식
                        ++nl;
                if(c ==' ' || c == '\n' || c== '\t') // 공백,\n,탭 나오면 단어라고 인식하기
                        state = OUT;
                else if (state ==OUT) {
                        state = IN;
                        ++nw;
                }
        }
        printf("%d %d %d\n",nl,nw,nc);
}
