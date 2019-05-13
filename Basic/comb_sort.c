#include <stdio.h>

void comb_sort(int a[], int size) {
	int i, temp;
	int gap = size;
	int swapped = 1;

	while (gap != 1 || swapped) {
		gap = gap / 1.3;

		if (gap < 1) gap = 1; {
			swapped = 0;
		}

		for (i = 0; i < size - gap; i++) {
			if (a[i] > a[i + gap]) {
				temp = a[i]; a[i] = a[i + gap];
				a[i + gap] = temp;
				swapped = 1;
			}
		}
	}
}
int main() {
	int arr[] = { 9,1,22,4,0,-1,1,22,100,10 };
	int size = sizeof(arr) / sizeof(int);
	comb_sort(arr, size);
	for (int i = 0; i < size; i++) printf("%d ", arr[i]);
	// -1 0 1 1 4 9 10 22 22 100 
}