#include<bits/stdc++.h>
using namespace std;

int main() {
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	


	if (num2 - 45 < 0) {
		num1--;
		if (num1 < 0)
			num1 = 23;
		num2 = num2 + 60 - 45;
		printf("%d %d", num1, num2);
	}
	else {
		if (num1 < 0)
			num1 = 23;
		printf("%d %d", num1, num2 - 45);
	}

	return 0;
}