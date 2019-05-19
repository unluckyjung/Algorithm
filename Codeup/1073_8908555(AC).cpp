#include<bits/stdc++.h>

int main() {
	int a;

reload:
	scanf("%d", &a);
	printf("%d\n", a);
	if (a == 0)
		return 0;
	goto reload;

	return 0;
}
