#include<bits/stdc++.h>
using namespace std;

int main() {
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			printf("%d %d\n", i, j);
		}
	}

	return 0;
}

