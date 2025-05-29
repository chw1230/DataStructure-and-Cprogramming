#include <stdio.h>
#include <string.h>

int main(void){
	char *s1 = "1234512345";
	char *s2 = "34";
	
	/* strspn(cs,ct) cs중 ct로 구성된 연속된 부분 문자열 길이 반환 + 앞에서 부터 한 문자 차례대로 존재하는지! 존재하지 않으면 끝남!
	 * strcspn(cs,ct) cs중 ct로 구성된 연속된 부분 문자열이 나오기 전까지의 길이 반환
	 * *strpbrk(cs,ct) cs 문자열에서 ct에 있는 문자들 중 하나라도 처음 등장하는 위치를 만환(포인터 반환)
	 */

	printf("%d\n",(int)strspn(s1,s2)); 
	printf("%s\n",strpbrk(s1,s2));
	return 0;
}
