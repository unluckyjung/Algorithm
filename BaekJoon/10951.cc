#include <stdio.h>

int main() {
	int a, b;

	while (scanf("%d %d", &a, &b) != EOF) {	//consider scanf return value
		printf("%d\n", a + b);
	}
	return 0;
}