﻿#include<bits/stdc++.h>

int main() {
	int n;

reload:
	scanf("%d", &n);

	printf("%d\n", n);
	if (n == 0)
		return 0;
	goto reload;

	return 0;
}
