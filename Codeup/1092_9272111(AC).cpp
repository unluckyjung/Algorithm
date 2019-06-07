#include<bits/stdc++.h>
using namespace std;

int main() {

	int n1, n2, n3;
	int day = 1;
	scanf("%d %d %d", &n1, &n2, &n3);
	while (1) {
		if (day % n1 == 0 && day%n2 == 0 && day%n3 == 0) {
			printf("%d\n", day);
			break;
		}
		day++;
	}
	return 0;
}
