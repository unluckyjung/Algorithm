#include<bits/stdc++.h>
using namespace std;


int main() {
	char al;
	char al2 = 'a';

	scanf("%c", &al);

	while (al >= 97) {
		printf("%c ", al2++);
		al--;
	}
	return 0;
}

