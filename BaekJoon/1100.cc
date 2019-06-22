#include <bits/stdc++.h>
using namespace std;
int main()
{
	char arr[8][9] = { 0, };
	int count = 0;

	for (int i = 0; i < 8; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (!((i + j) % 2))
				if (arr[i][j] == 'F')
					count++;
		}
	}

	printf("%d", count);

	return 0;
}