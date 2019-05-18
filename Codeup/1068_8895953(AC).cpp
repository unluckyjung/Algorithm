#include<bits/stdc++.h>

int main() {
	int grade;
	scanf("%d", &grade);
	
	if (grade >= 90)
		printf("A\n");
	else if (grade >= 70)
		printf("B\n");
	else if (grade >= 40)
		printf("C\n");
	else
		printf("D\n");
	return 0;
}
