#include<bits/stdc++.h>
using namespace std;

int main() {
	int num1;
	int num2 = 0, sum = 0;

	scanf("%d", &num1);
	while (sum < num1) {
		num2++;
		sum += num2;
	}
	printf("%d\n", num2);

	return 0;
}

