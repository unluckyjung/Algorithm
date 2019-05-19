#include<bits/stdc++.h>

int main() {
	int n;

reload:
	scanf("%d", &n);	//3 5가 입력시

	printf("%d\n", n);	//3을 받아서 3\n이 출력되고 다시 5를받아서 5\n이 출력된다.
	if (n == 0)
		return 0;
	goto reload;

	return 0;
}