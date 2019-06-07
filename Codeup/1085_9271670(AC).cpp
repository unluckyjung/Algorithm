#include<bits/stdc++.h>
using namespace std;

int main() {
	int n1, n2, n3, n4;
	scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
	printf("%.1f MB", (double)n1*n2*n3*n4/(8*pow(2,20)));


	return 0;
}

