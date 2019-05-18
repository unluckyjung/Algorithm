#include<bits/stdc++.h>

int main() {
	int grade;
	scanf("%d", &grade);
	
	if (grade == 12 || grade == 1 || grade == 2)
		printf("winter\n");
	else if (grade == 3 || grade == 4 || grade == 5)
		printf("spring\n");
	else if (grade == 6 || grade == 7 || grade == 8)
		printf("summer\n");
	else
		printf("fall\n");
	return 0;
}
