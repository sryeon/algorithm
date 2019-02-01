/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){

	char alpa[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	int alpaIndex = 0;
	int whileIndex = 0;
	int refValue1, refValue2;

    char ** ptr_rhombus;

	int size;
	int width;
	int height;

	scanf("%d", &size);

	if(!(size > 0 && size <= 100)){
		printf("INPUT ERROR!");
		return 0;
	}

	width = 4*size;
	height = 2*size -1;

	ptr_rhombus = (char **)malloc(height * sizeof(char*));

	for(int i=0;i<(2*size-1);i++){
		ptr_rhombus[i] = (char *)malloc(width*sizeof(char));
		memset(ptr_rhombus[i],' ', width);
		ptr_rhombus[i][width-1] = '\0';
	}

	while(1){
		refValue1 = whileIndex;
		refValue2 = size - (whileIndex);

		if(refValue2 == 0)
			break;

		for(int i=0;i<refValue2;i++){
			ptr_rhombus[i + refValue1][((refValue2-1) - i + refValue1)*2] = alpa[alpaIndex];
			
			if(alpaIndex == 25)
				alpaIndex = 0;
			else
				alpaIndex++;
		}
		
		for(int i=1;i<refValue2;i++){
			ptr_rhombus[(refValue2 - 1) + i+ refValue1][(i+ refValue1)*2] = alpa[alpaIndex];
			
			if(alpaIndex == 25)
				alpaIndex = 0;
			else
				alpaIndex++;
		}

		for(int i=1;i<refValue2;i++){
			ptr_rhombus[(2*refValue2 - 2) - i+ refValue1][((refValue2 - 1)+ i + refValue1)*2] = alpa[alpaIndex];
			
			if(alpaIndex == 25)
				alpaIndex = 0;
			else
				alpaIndex++;
		}

		for(int i=1;i<refValue2 -1;i++){
			ptr_rhombus[(refValue2 - 1) - i+ refValue1][((2*refValue2 - 2) - i+ refValue1)*2] = alpa[alpaIndex];
			
			if(alpaIndex == 25)
				alpaIndex = 0;
			else
				alpaIndex++;
		}

		whileIndex++;
	}

	for(int i=0;i<height;i++){
		printf("%s\n", ptr_rhombus[i]);
	}

	free(ptr_rhombus);

	system("pause");
}
*/
