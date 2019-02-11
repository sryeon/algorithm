#include <stdio.h>
#include <stdlib.h>

void QuickSort(int arr[], int left, int right) {
  int L = left, R = right;
  int temp;
  int pivot = arr[(left + right) / 2]; //피봇 위치(중앙)의 값을 받음.

  while (L <= R) {

    while (arr[L] < pivot) //left부터 증가하며 pivot 이상의 값을 찾음.
      L++;
    while (arr[R] > pivot) //right부터 감소하며 pivot 이하 값을 찾음.
      R--;
  
    if (L <= R) { //현재 L이 R이하면. (이유 : L>R 부분은 이미 정리가 된 상태임).
      if (L != R) { //같지 않은 경우만.
        temp = arr[L];
        arr[L] = arr[R];
        arr[R] = temp;
      } //L과 R이 같다면 교환(SWAP)은 필요 없고 한 칸씩 진행만 해주면 됨.
      L++; R--; //그리고 L,R 한 칸 더 진행.

    }
  }

  if (left < R)
    QuickSort(arr, left, R);
  if (L < right)
    QuickSort(arr, L, right);
}

int main (void){

	int array_a[50];
	int array_b[50];

	int N;
	int S = 0;

	scanf("%d", &N);

	if(!(N>=1 && N<=50)){
		printf("INPUT ERROR!\n");
		return 0;
	}

	for(int i=0;i<N;i++){
		scanf("%d", &array_a[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d", &array_b[i]);
	}

	QuickSort(array_a, 0, N-1);
	QuickSort(array_b, 0, N-1);

	for(int i=0;i<N;i++){
		//printf("%d, %d \n", array_a[i], array_b[(N-1)-i]);
		S = S + (array_a[i] * array_b[(N-1)-i]);
	}
	
	printf("%d\n", S);

	//system("pause");
}

