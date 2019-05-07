#include <stdio.h>

void swap(int* a, int* b) { // SWAP 함수
	int tmp = *a;
	*a = *b;
	*b = tmp;
}



void heapify(int A[], int k, int n) { //heap_sort의 핵심

	int left = 2 * k;  // k의 좌측 노드 값
	int right = 2 * k + 1; // k의 우측 노드 값
	int large = k; //가장 윗 노드를 큰값으로 생각.


	if (right <= n) { // 우측 노드가 n 값보다 작을경우
		if (A[large] < A[left]) //맨위의 노드가 좌측보다 작다면
			large = left; //좌측이 large
		if (A[large] < A[right])//우측이 좌측보다크다면
			large = right;//우측이 large
	}

	else if (left <= n) //좌측이 n보다 작을경우,
		if (A[large] < A[left]) large = left;//좌측이 맨 위 노드보다 클경우 large가 됌.
		else
			return; //둘다 해당하지 않을경우, 즉 k값을 곱해서 얻은 좌우측이 전부 전체 노드의 길이(n)보다 클경우에는 아무것도 하지않고 리턴해서 빠져나감.

	if (A[large] > A[k]) { //정의된 large값이 k 노드값 보다 크다면
		swap(&A[large], &A[k]); //k의 값과 large값을 맞바꾼다.
		heapify(A, large, n); //heap의 성질이 깨졌으므로, 성질을 유지하기위해서 다시 받은 값들로 heapify작업을 돌린다. 

	}

}



void build_heap(int A[], int n) {
	for (int i = n / 2; i >= 0; i--)
		heapify(A, i, n); //들어온값을 받은뒤, 조건문내에서 heapify를 돌린다.

}



void heap_sort(int A[], int n) { //자기가 자기를 부르는 sort방식
	build_heap(A, n);  // heap을 build한다.
	for (int i = n; i >= 1; i--) { //heap의 크기가 1이 될떄까지 반복한다.(더이상 heap을 할것이 없을때까지)
		swap(&A[0], &A[i]); //맨 위의 노드와, 맨 아래의 노드를 교환한다(build_heap을 거치고와서, 맨아래에 위치한 노드가 제일 작기때문에)
		heapify(A, 0, i - 1);
	} //작업을 마치고나면, 오름차순으로 정렬이된다.
}


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

	heap_sort(A, 99);

	printf("\n");

	printf("정렬후\n");
	for (i = 0; i < 100; i++)
		printf("%d ", A[i]);


	return 0;

}
