#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){

	int num;
	int *ptr_init_array;
	int *ptr_logic_array;
	int *ptr_temp_array;

	int logic_count = 1;
	bool breakFlag = true;
	//������ ������ ����
	scanf("%d", &num);

	if(!(num > 0 && num <= 20000)){
		printf("INPUT ERROR!");
		return 0;
	}

	ptr_init_array = (int *)malloc(num * sizeof(int));
	ptr_logic_array = (int *)malloc(num * sizeof(int));
	ptr_temp_array = (int *)malloc(num * sizeof(int));

	//������ �Է¹޴´�.
	for(int i=0;i<num;i++){
		scanf("%d", &ptr_init_array[i]);
		ptr_logic_array[i] = i+1; //1���� �����ϴ� ī�带 ��ġ
	}

	while(breakFlag){

		for(int i=0;i<num;i++){
			ptr_temp_array[i] = ptr_logic_array[ptr_init_array[i] -1];
		}

		memcpy(ptr_logic_array, ptr_temp_array, num * sizeof(int));

		for(int i=0;i<num;i++){
			if(ptr_logic_array[i] != i+1){
				logic_count++;
				break;
			}

			if(i == num-1){
				breakFlag = false;
			}
		}
	}
	printf("%d\n", logic_count);

	free(ptr_init_array);
	free(ptr_logic_array);
	free(ptr_temp_array);
	
	//system("pause");

}

