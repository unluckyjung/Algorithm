#include<bits/stdc++.h>

int main() {
	int n1, n2, n3;
	scanf("%d %d %d", &n1, &n2, &n3);
	printf("%d", (n1 < n2 ? n1 : n2) < n3 ? (n1 < n2 ? n1 : n2) : n3);
	//n1이 n2보다 작다면 n1이 선정되어짐. 이것이 n3 보다 작다면, 
	//n1 선정되고, 아니면 n3이된다.
	return 0;
}
