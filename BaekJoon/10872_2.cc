#include <bits/stdc++.h>
using namespace std;

void fac(int& N) {
	int sum = 1;
	for (int i = 1; i <= N; ++i) sum *= i;
	cout << sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;

	int N;
	cin >> N;
	fac(N);

	return 0;
}