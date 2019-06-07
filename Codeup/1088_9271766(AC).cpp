#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int i = 0;
	scanf("%d", &n);

	while (i<n) {
		i++;
		if (i % 3 != 0)
			printf("%d ", i);
	}

	return 0;
}

