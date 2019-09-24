#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> cnt;
	while (cnt--) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}

	return 0;
}