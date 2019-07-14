#include<bits/stdc++.h>
using namespace std;

int main() {

	int num;
	int answer = 1;
	scanf("%d", &num);

	while (num) {
		answer = answer * num;
		num--;
	}

	printf("%d", answer);
	return 0;
}