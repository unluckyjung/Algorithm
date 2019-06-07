#include<bits/stdc++.h>
using namespace std;

int main() {
	int num;
	int num2;
	int arr[10000] = { 0, };

	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf("%d", &num2);
		getchar();	//엔터 버퍼를 지워준다.
		arr[i] = num2;
	}

	for (int i = num; i >= 1; i--) {
		printf("%d ", arr[i]);
	}
	return 0;
}
