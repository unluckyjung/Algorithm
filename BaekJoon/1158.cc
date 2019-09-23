#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	list<int> l;

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; ++i) l.push_back(i);

	//cout << l.front();
	//cout << l.back();

	auto it = l.begin();
	cout << "<";
	while (!l.empty()) {
		for (int i = 0; i < K-1; ++i) {
			it++;
			if (it == l.end()) it = l.begin();
		}
		if (l.size() == 1) {
			cout << *it << ">";
			return 0;
		}
		cout << *it << ", ";
		it = l.erase(it);
		if (it == l.end()) it = l.begin();
	}
	return 0;
}