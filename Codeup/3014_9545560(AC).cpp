#include<bits/stdc++.h>

int main() {

	int num;
	int arr[100001] = { 0, };
	int n1;

	scanf("%d", &num);

	for (int i = 0; i < num; ++i) {
		scanf("%d", &n1);
		arr[n1]++;
	}

	for (int i = 0; i < 100001; ++i) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; ++j) {
				printf("%d ", i);
			}
		}
	}
	return 0;
}

