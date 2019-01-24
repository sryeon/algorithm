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
    //������ ������ ����
    scanf("%d", &num);
 
    if(!(num > 0 && num <= 20000)){
        printf("INPUT ERROR!");
        return 0;
    }

    ptr_init_array = (int *)malloc(num * sizeof(int));
    ptr_logic_array = (int *)malloc(num * sizeof(int));
    ptr_temp_array = (int *)malloc(num * sizeof(int));
    ptr_lcm_array = (int *)malloc(num * sizeof(int));
     
    //������ �Է¹޴´�.
    for(int i=0;i<num;i++){
        scanf("%d", &ptr_init_array[i]);
        ptr_logic_array[i] = i+1; //1���� �����ϴ� ī�带 ��ġ
        ptr_lcm_array[i] = 0; // lcm���� �ʱ�ȭ
    }
 
	lcm_count = 0;
    while(1){
 
		//��������1ȸ ����. �Ʒ� for���� ����, ������ ���� ī�尡 1ȸ ����. �� ��������+1
        for(int i=0;i<num;i++){
			// üũ�ߴ� ���̸� �����񱳷� �Ѿ.
			if(ptr_lcm_array[i] != 0){
				continue;
			}
			
			// ���� ����
			logic_value = ptr_logic_array[ptr_init_array[i] -1];

			// üũ������ ���� �ȿ����̴� ���̸� üũ�ϷḦ ó���� ��, �����񱳷� �Ѿ.
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

			//���� ����
            ptr_temp_array[i] = logic_value;

            // üũ������ ���� �ʱⰪ�� ��ġ�ϴ� ���̸�?
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
				//���� üũȽ���� ����ؼ�, ���� ���� ���� LCM������ �¿��� ����.
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