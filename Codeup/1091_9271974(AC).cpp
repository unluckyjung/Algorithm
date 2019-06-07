#include<bits/stdc++.h>
using namespace std;

int main() {

	int a, m, d, n;
	int result;
	scanf("%d %d %d %d", &a, &m, &d, &n);
	if (n == 1) {
		printf("%d\n", a);
		return 0;
	}
	result = a * m + d;
	for (int i = 2; i < n; i++) {
		result = result * m + d;
	}
	printf("%d\n", result);
	return 0;
}
