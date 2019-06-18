#include<bits/stdc++.h>

int main() {

	int num;
	int arr[19][19] = { 0, };



	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			scanf("%d ", &arr[i][j]);
		}
	}

	scanf("%d", &num);

	int num2, num3;

	for(int j = 0 ; j<num; j++){

		scanf("%d %d", &num2, &num3);
		for (int i = 0; i < 19; i++) {


			if (arr[num2-1][i] == 0)
				arr[num2-1][i] = 1;
			else
				arr[num2-1][i] = 0;



			if (arr[i][num3-1] == 0)
				arr[i][num3-1] = 1;
			else
				arr[i][num3-1] = 0;
		}
	}


	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
