#include <bits/stdc++.h>


int main()
{
	int arr[10][10] = { 0, };
	int wall;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &wall);
			arr[i][j] = wall;
		}
	}

	
	int x = 1, y = 1;
	int flag = 0;
	while (1) {

		if (arr[x][y] == 1)
			break;

		if (arr[x][y] == 2) {
			arr[x][y] = 9;
			break;
		}

		if (arr[x][y+1] != 1) {
			arr[x][y] = 9;
			y++;
		}
		else{
			arr[x][y] = 9;
			x++;
		}
	}
	

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

