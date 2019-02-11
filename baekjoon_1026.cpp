#include <stdio.h>
#include <stdlib.h>

void QuickSort(int arr[], int left, int right) {
  int L = left, R = right;
  int temp;
  int pivot = arr[(left + right) / 2]; //�Ǻ� ��ġ(�߾�)�� ���� ����.

  while (L <= R) {

    while (arr[L] < pivot) //left���� �����ϸ� pivot �̻��� ���� ã��.
      L++;
    while (arr[R] > pivot) //right���� �����ϸ� pivot ���� ���� ã��.
      R--;
  
    if (L <= R) { //���� L�� R���ϸ�. (���� : L>R �κ��� �̹� ������ �� ������).
      if (L != R) { //���� ���� ��츸.
        temp = arr[L];
        arr[L] = arr[R];
        arr[R] = temp;
      } //L�� R�� ���ٸ� ��ȯ(SWAP)�� �ʿ� ���� �� ĭ�� ���ุ ���ָ� ��.
      L++; R--; //�׸��� L,R �� ĭ �� ����.

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

