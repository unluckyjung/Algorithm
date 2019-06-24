#include<bits/stdc++.h>
using namespace std;

int findsum(int num) {
	int sum = num;

	while (num != 0) {
		sum += num % 10;	//123 % 10 = [3]	12 % 10 = [2]	1 % 10 = [1]
		num = num / 10;		//123 / 10 = 12		12 / 10 = 1		1 / 10 = 0
	}
	return sum;
}

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; ++i) {
		if (findsum(i) == num) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("0\n");


	return 0;
}