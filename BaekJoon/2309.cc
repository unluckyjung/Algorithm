#include<bits/stdc++.h>
using namespace std;

int main() {
	int arr[9] = { 0, };
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	sort(arr, arr + 9);
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 9; j++) {
			if (100 == sum - arr[i] - arr[j])
				break;
		}
		if (100 == sum - arr[i] - arr[j])	//여기서도 for문을 빠져나가게 해줘야한다.
			break;
	}

	for (int z = 0; z < 9; z++) {

		if (z == i || z == j)
			continue;
		printf("%d\n", arr[z]);
	}

	return 0;
}