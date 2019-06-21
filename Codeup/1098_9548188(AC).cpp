#include<bits/stdc++.h>

int main() {

	int arr[101][101] = { 0, };

	int w, h;
	int n;
	int l, d, x, y;

	scanf("%d %d", &h, &w);
	scanf("%d", &n);

	while (n--) {
		scanf("%d %d %d %d", &l, &d, &x, &y);
		if (d == 0) {
			arr[x - 1][y - 1] = 1;
			for (int i = 1; i < l; i++) {
				arr[x - 1][y - 1 + i] = 1;
			}
		}
		else {
			arr[x - 1][y - 1] = 1;
			for (int i = 1; i < l; i++) {
				arr[x - 1 + i][y - 1] = 1;
			}
		}
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

