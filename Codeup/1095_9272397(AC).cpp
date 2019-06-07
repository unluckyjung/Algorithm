#include<bits/stdc++.h>
using namespace std;

int main() {
	int num;
	int num2;
	int min;

	scanf("%d", &num);
	min = 100;
	for (int i = 1; i <= num; i++) {
		scanf("%d", &num2);
		getchar();	//엔터 버퍼를 지워준다.
		if (min > num2)
			min = num2;
	}

	printf("%d\n", min);

	return 0;
}
