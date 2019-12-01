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

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;

	for (int i = 0; i < 8; ++i) {
		string str;	cin >> str;
		int str_index = 0;

		if (i % 2 != 0) str_index++;

		for (; str_index < 8; str_index += 2) {
			if (str[str_index] == 'F')sum++;
		}
	}

	cout << sum;
	return 0;
}