#include<bits/stdc++.h>
using namespace std;

int main() {
	int n1, n2, n3;
	scanf("%d %d %d", &n1, &n2, &n3);
	printf("%.2f MB", (double)n1*n2*n3/(8*pow(2,20)));


	return 0;
}

