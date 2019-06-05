#include<bits/stdc++.h>
using namespace std;

int main() {
	int num;
	scanf("%x", &num);
	for (int i = 1; i < 16; i++) {
		printf("%X*%X=%X\n", num, i,num*i);
	}

	return 0;
}

