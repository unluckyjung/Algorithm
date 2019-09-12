#include <bits/stdc++.h>
using namespace std;

int fibo[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fibo[0] = 0;
	fibo[1] = 1;


	for(int i = 2; i <= 45; ++i) {
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}

	int n;
	cin >> n;
	cout << fibo[n];

	return 0;
}