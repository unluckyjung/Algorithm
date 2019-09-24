#include <bits/stdc++.h>
using namespace std;
//11931 수 정렬하기4
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	//priority_queue<int, vector<int>, greater<int>> pq;
	priority_queue<int> pq;

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