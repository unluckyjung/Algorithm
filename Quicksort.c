#include <stdio.h>

void swap(int* a, int* b) { // SWAP 함수
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int A[], int p, int r) { // 파티션 함수, Quick Sort의 핵심
	int x = A[r], i = p - 1, j; // i값을 p-1로 두는 이유는, i는 key값보다 작은 파티션 부분이기 때문, 즉 처음에는 배열에 없다고 생각하고 시작해야함.
	for (j = p; j < r; j++)
		if (A[j] <= x) swap(&A[++i], &A[j]); //배열의 수가 key값보다 작을경우에는, i 파티션(key값보다 작음)을 하나 증가 시킨다, 아닐경우에는 j 파티션(key값보다 큼)을 증가시킨다.
	swap(&A[++i], &A[r]); //마지막에 i와 j 사이에 key값을 다시 가지고온다.
	return i;

}


void quick_sort(int A[], int p, int r) { // Quick Sort
	if (p < r) {
		int q = partition(A, p, r); //파티션 함수를 통해, q값을 가져옴
		quick_sort(A, p, q - 1); //앞부터, q값 (전) 까지 sort
		quick_sort(A, q + 1, r);//q값{ 후 } 부터, 마지막까지 sort
	}
}

/* 
int main(void)
{
	int i;
	int A[100] = {};
	for (i = 0; i < 100; i++)
		if (i % 2) A[i] = (100 - i) * 3 + 1;
		else A[i] = i * 2 + 1;

	printf("정렬전\n");
	for (i = 0; i < 100; i++)
		printf("%d ", A[i]);

	printf("\n");

	quick_sort(A, 0, 99);

	printf("\n");

	printf("정렬후\n");
	for (i = 0; i < 100; i++)
		printf("%d ", A[i]);


	return 0;

}
*/