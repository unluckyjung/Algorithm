#include<bits/stdc++.h>
using namespace std;


int main() {
	int num;
	int sum = 0;
	scanf("%d", &num);

	while(num) {
		if (!(num&1))
			sum += num;
		num--;
	}
	printf("%d\n", sum);
	return 0;
}

