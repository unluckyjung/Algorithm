#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	set<int> s;
	while (cnt--) {
		int num;
		cin >> num;
		s.insert(num);
	}

	cout << *s.begin() << " " << *s.rbegin();
	return 0;
}