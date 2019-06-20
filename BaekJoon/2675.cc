#include<bits/stdc++.h>

int main() {
	char str[20] = { 0, };
	int num, num2;
	scanf("%d", &num);
	while (num--) {
		
		scanf("%d %s", &num2, str);
		for (int i = 0; i < strlen(str); i++) {
			for(int j = 0; j < num2; j++)
				printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}
