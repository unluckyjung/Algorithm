#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;

	int N, X;
	cin >> N >> X;
	while (N--) {
		int num1;
		cin >> num1;
		if(num1 < X) v.push_back(num1);
	}

	for (const auto& i : v)
		cout << i << " ";

	return 0;
}