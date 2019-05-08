#include<bits/stdc++.h>

int main() {
	
	int num;
	int div = 10000;
	scanf("%d", &num);

	if (10000 <= num && num <= 99999) {
		while (num > 0) {

			printf("[%d]\n", num / div * div);
			num = num % div;
			div = div / 10;
		}
	}

	return 0;
}
