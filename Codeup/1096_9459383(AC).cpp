#include<bits/stdc++.h>

int main() {

	int num;
	int x, y;
	int arr[19][19] = { 0, };
	
	scanf("%d", &num);

	for (int i = 0; i < num; ++i) {
		scanf("%d %d", &x, &y);
		arr[x-1][y-1] = 1;
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
