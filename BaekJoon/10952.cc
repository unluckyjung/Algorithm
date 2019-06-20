#include<bits/stdc++.h>

int main() {
	int n1, n2;
	
	scanf("%d %d", &n1, &n2);
	while (n1*n2) {
		printf("%d\n", n1 + n2);
		scanf("%d %d", &n1, &n2);
	}
	return 0;
}
