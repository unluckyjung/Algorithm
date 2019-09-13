#include <bits/stdc++.h>
using namespace std;

int arr[42];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 10;
	while (count--) {
		int num;
		cin >> num;
		arr[num % 42]++;
	}

	int sum = 0;
	for (int &i : arr) {
		if (i != 0) sum++;
	}
	cout << sum;
	return 0;
}