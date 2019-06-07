#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int i = 0;
	int sum = 0;
	scanf("%d", &n);

	while (1) {
		if (sum >= n)
			break;

		sum += i;
		i++;
	}
	printf("%d\n", sum);


	return 0;
}

