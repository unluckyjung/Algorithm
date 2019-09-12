#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	int sum = 0;
	cin >> count;
	for (int i = 0; i <= count; ++i) {	//위
		for (int j = i; j <= count; ++j) {	//아래
			sum += i + j;
		}
	}
	cout << sum;

	return 0;
}