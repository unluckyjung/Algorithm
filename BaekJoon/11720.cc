#include<bits/stdc++.h>
using namespace std;
char arr[101] = { 0, };

int main() {

	int num;
	int sum = 0;
	scanf("%d", &num);
	scanf("%s" , arr);

	for (int i = 0; i < num; ++i) {
		sum = sum + (arr[i] - 48);
	}

	printf("%d", sum);
	return 0;
}