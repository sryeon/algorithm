#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){

	int s, e, temp;

	while(1){
		scanf("%d %d", &s, &e);

		if(!(s>1 && s<10)){ 
			printf("INPUT ERROR!\n");
			continue;
		}
		if(!(e>1 && e<10)){
			printf("INPUT ERROR!\n");
			continue;
		}

		//swap
		if(s > e){
			for(int j=1; j<10; j++){
				for(int i=s; i>=e; i--){
					printf("%d * %d = %2d   ", i, j, i*j);
				}
				printf("\n");
			}	
		}else {
			for(int j=1; j<10; j++){
				for(int i=s; i<=e; i++){
					printf("%d * %d = %2d   ", i, j, i*j);
				}
				printf("\n");
			}
		}

		break;
	}
	


	system("pause");
}

