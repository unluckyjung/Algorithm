#include <bits/stdc++.h>
using namespace std;


int answer() {
	priority_queue<int> pq;
	int W = 10;

	while (W--) {
		int num;
		cin >> num;
		pq.push(num);
	}
	
	int cnt = 3;
	int sum = 0;
	while (cnt--) {
		sum += pq.top();
		pq.pop();
	}
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << answer() << " " << answer();

	return 0;
}