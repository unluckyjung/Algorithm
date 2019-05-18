#include<bits/stdc++.h>

int main() {
	int num[3] = { 0, };

	scanf("%d%d%d", &num[0], &num[1], &num[2]);

	for (int i = 0; i < 3; i++) {
		if (num[i] % 2 == 0)
			printf("even\n");
		else
			printf("odd\n");
	}
	return 0;
}
