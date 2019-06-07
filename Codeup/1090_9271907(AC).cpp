#include<bits/stdc++.h>
using namespace std;

int main() {

	int a, r, n;
	scanf("%d %d %d", &a, &r, &n);
	printf("%d\n", a * (int)pow(r, n - 1));

	return 0;
}
