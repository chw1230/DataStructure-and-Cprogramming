#include <stdio.h>

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

int main(void){
	int month, day ,year;
	char monthname[20];
	char line[100];

	while (Mygetline(line,sizeof(line)) > 0) {
       	 	// 첫 번째 형식: 25 Dec 1988
        	if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3) {// 공백 무시
            		printf("valid: %s (형식: 25 Dec 1988)\n", line);
        	}
		// 두 번째 형식: 12/25/1988
		else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3) { // 입력 문자열과 정확하게 일치해야함
			printf("valid: %s (형식: mm/dd/yyyy)\n", line);
		} 
	 	else {
	    		printf("invalid: %s\n", line);
		}
    	}
}


