#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}
int lcm(int a, int b)
{
    return a / gcd(a, b)*b;
}
 
int main (void){
 
    int num;
    int *ptr_init_array;
    int *ptr_logic_array;
    int *ptr_temp_array;
    int *ptr_lcm_array;
 
    int logic_count = 1;
	int before_logic_count = 0;
	int logic_value;
    int lcm_count = 0;
	bool lcm_init_flag = false;

    long lcm_value;
 
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
     
    //수열을 입력받는다.
    for(int i=0;i<num;i++){
        scanf("%d", &ptr_init_array[i]);
        ptr_logic_array[i] = i+1; //1부터 증가하는 카드를 배치
        ptr_lcm_array[i] = 0; // lcm값들 초기화
    }
 
	lcm_count = 0;
    while(1){
 
		//수열로직1회 실행. 아래 for문을 돌면, 수열을 통해 카드가 1회 섞임. 즉 수열궤적+1
        for(int i=0;i<num;i++){
			// 체크했던 놈이면 다음비교로 넘어감.
			if(ptr_lcm_array[i] != 0){
				continue;
			}
			
			// 로직 수행
			logic_value = ptr_logic_array[ptr_init_array[i] -1];

			// 체크한적이 없고 안움직이는 놈이면 체크완료를 처리한 후, 다음비교로 넘어감.
			if(ptr_logic_array[i] == logic_value){
				ptr_lcm_array[i] = 1;
				
				if(lcm_init_flag == false){
					lcm_value = 1;
					lcm_init_flag = true;
				}
				lcm_count++;

				if(lcm_count == num){
					breakFlag = false;
					break;
				}
				continue;
			}

			//로직 저장
            ptr_temp_array[i] = logic_value;

            // 체크한적이 없고 초기값과 일치하는 놈이면?
            if(ptr_temp_array[i] == i+1){
                ptr_lcm_array[i] = logic_count;

				if(lcm_init_flag == false){
					lcm_value = ptr_lcm_array[i];
					lcm_init_flag = true;
				}else if(before_logic_count != logic_count){
					lcm_value = lcm(lcm_value, ptr_lcm_array[i]);
					//printf("ptr_lcm_array[%d] : %d / lcm_value : %d\n", i, ptr_lcm_array[i], lcm_value);
				}
				lcm_count++;

				if(lcm_count == num){
					breakFlag = false;
					break;
				}
				//이전 체크횟수를 기억해서, 같은 수는 굳이 LCM로직을 태우지 않음.
				before_logic_count = logic_count;
            }
        }

		if(breakFlag == false)
			break;

		memcpy(ptr_logic_array, ptr_temp_array, num * sizeof(int));

        logic_count++;
    }
     
    printf("%d\n", lcm_value);
 
    free(ptr_init_array);
    free(ptr_logic_array);
    free(ptr_temp_array);
    free(ptr_lcm_array);
     
    system("pause");
 
}