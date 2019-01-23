#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int EU(int x, int y){
	int n;
	while(1){
		n = x % y;
		if(n==0) return y;
		x = y;
		y = n;
	}
}

int main (void){

	int num;
	int *ptr_init_array;
	int *ptr_logic_array;
	int *ptr_temp_array;
	int *ptr_lcm_array;
	int *ptr_lcm_overlap_array;

	int logic_count = 1;
	int lcm_count = 0;
	long lcm_value;
	long gcm_value;

	bool breakFlag = true;
	//수열의 갯수를 지정
	scanf("%d", &num);

	if(!(num > 0 && num <= 20000)){
		printf("INPUT ERROR!");
		return 0;
	}

	ptr_init_array = (int *)malloc(num * sizeof(int));
	ptr_logic_array = (int *)malloc(num * sizeof(int));
	ptr_temp_array = (int *)malloc(num * sizeof(int));
	ptr_lcm_array = (int *)malloc(num * sizeof(int));
	ptr_lcm_overlap_array = (int *)malloc(num * sizeof(int));
	
	//수열을 입력받는다.
	for(int i=0;i<num;i++){
		scanf("%d", &ptr_init_array[i]);
		ptr_logic_array[i] = i+1; //1부터 증가하는 카드를 배치
		ptr_lcm_array[i] = 0;  // lcm값들 초기화
	}

	while(breakFlag){

		for(int i=0;i<num;i++){
			ptr_temp_array[i] = ptr_logic_array[ptr_init_array[i] -1];
		}

		memcpy(ptr_logic_array, ptr_temp_array, num * sizeof(int));

		lcm_count = 0;

		for(int i=0;i<num;i++){
			// 초기값과 일치하면서 lcm값이 없던 놈이면?
			if((ptr_lcm_array[i] == 0) && (ptr_logic_array[i] == i+1)){
				ptr_lcm_array[i] = logic_count;
			}

			// lcm값이 모두 할당되었는지 체크.
			if(ptr_lcm_array[i] != 0){
				lcm_count++;
			}

			if(lcm_count == num){
				breakFlag = false;
			}
		}

		logic_count++;
	}
	
	//ptr_lcm_array 중복 제거.
	int overlap_index = 1;
	ptr_lcm_overlap_array[0] = ptr_lcm_array[0];
	for(int i=1;i<num;i++){
		for(int j=0;j<overlap_index;j++){

			if(ptr_lcm_array[i] == ptr_lcm_overlap_array[j])
				break;

			if(j == overlap_index -1){
				ptr_lcm_overlap_array[overlap_index] = ptr_lcm_array[i];
				overlap_index++;
			}
		}
	}

	//최소 공배수 구하기
	gcm_value = ptr_lcm_overlap_array[0];
	lcm_value = ptr_lcm_overlap_array[0];

	for(int i=1;i<overlap_index;i++){
		gcm_value = EU(gcm_value, ptr_lcm_overlap_array[i]);
		lcm_value = lcm_value * ptr_lcm_overlap_array[i] / EU(lcm_value, ptr_lcm_overlap_array[i]);
	}
	
	printf("%d\n", lcm_value);

	free(ptr_init_array);
	free(ptr_logic_array);
	free(ptr_temp_array);
	free(ptr_lcm_array);
	free(ptr_lcm_overlap_array);
	
	system("pause");

}

