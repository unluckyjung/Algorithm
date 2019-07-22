#include<bits/stdc++.h>

void hanoi(int n, int n1, int n2, int n3) {
	if (n == 1) {
		printf("%d %d\n", n1, n3);
	}
	else {
		hanoi(n - 1, n1, n3, n2);
		printf("%d %d\n", n1, n3);
		hanoi(n - 1, n2, n1, n3);
	}
}

int main() {
	int number;
	scanf("%d", &number);

	printf("%d\n", (1<<number)-1);
	hanoi(number, 1,2,3);

	return 0;
}
