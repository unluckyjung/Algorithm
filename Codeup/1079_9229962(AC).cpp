#include<bits/stdc++.h>
using namespace std;

int main() {
	char alpha[5];

	while (1) {
		scanf("%s", &alpha);
		if (!(strcmp(alpha, "q"))) {
			printf("%s\n", alpha);
			break;
		}
		printf("%s\n", alpha);
	}
	return 0;
}

