#include <stdio.h>

int main(void) {

	int n;
	scanf("%d",&n);
	int i = 2;
	while ( n > 1 ){
                 if ( n % i == 0){
                         n = n/i;
  	                 printf("%d",i);
         		if( n != 1){
                               printf("*");
                        }

                 } else {
                        i++;
                 }
       }
}
