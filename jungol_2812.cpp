#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int getDigits(long long int number){

	int cnt = 1;
	
	while(1){

		number = number/10;

		if(number <= 0)
			break;

		cnt++;
	}

	return cnt;
}
int getSumDigitsNum(long long int number, int digits){

	int temp =0;
	int sum = 0;

	//printf("========%lld\n", number);

	for(int i=0;i<digits;i++){
		temp = number/pow((double)10, (double)(digits-1) - i);

		sum += temp;

		number -= (long long int)(temp * pow((double)10, (double)(digits-1) - i));

		//printf("temp : %d, sum : %d, number : %lld \n", temp, sum, number);
		//printf("temp * pow((double)10, (double)(digits-1) - i) : %lld \n", (long long int)(temp * pow((double)10, (double)(digits-1) - i)));
	}

	return sum;
}

int main (void){

	long long int num;
	int sum_all = 0;
	
	int num_digits;

	scanf("%lld", &num);
	
	//printf("%lld\n", num);
	
	if(!(num > 0 && num <= pow((double)2, (double)63) -1)){
        printf("INPUT ERROR!");
        return 0;
    }

	num_digits = getDigits(num);
	//printf("%d\n", num_digits);

	sum_all = getSumDigitsNum(num, num_digits);

	printf("%d\n", sum_all);

	int num_digits_under10;
	int sum_under10 = sum_all;
	while(1){

		if(sum_under10 < 10)
			break;

		num_digits_under10 = getDigits((long long int)sum_all);

		sum_under10 = getSumDigitsNum((long long int)sum_under10, num_digits_under10);

		printf("%d\n", sum_under10);
	}
	
	system("pause");
}

