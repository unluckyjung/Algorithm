#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n1, n2, n3;
	int result;
	cin >> n1 >> n2 >> n3;
	result = n1 * n2 * n3;

	while (result) {
		arr[result % 10] ++;
		result /= 10;
	}

	for (int i = 0; i < 10; ++i) cout << arr[i] << "\n";
	return 0;
}