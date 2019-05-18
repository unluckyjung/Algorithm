#include<bits/stdc++.h>

int main() {
	int n, a;
	scanf("%d", &n);

reload:
	scanf("%d", &a);
	printf("%d\n", a);
	n--;
	if (n == 0)
		return 0;
	goto reload;

	return 0;
}
