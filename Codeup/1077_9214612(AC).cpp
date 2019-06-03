#include<bits/stdc++.h>
using namespace std;


int main() {
	int num;
	int count = 0;
	scanf("%d", &num);
	while (num >= 0) {
		printf("%d\n", count++);
		num--;
	}

	return 0;
}

