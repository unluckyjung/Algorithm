#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//clock_t start, stop;
	//start = clock();
	////function
	//stop = clock();

	int cnt;
	cin >> cnt;
	
	while (cnt--) {
		int sum = 0;
		int T = 7;
		priority_queue<int, vector<int>, greater<int>> pq;

		while (T--) {
			int num = 0;
			cin >> num;
			if (num & 1)continue;
			sum += num;
			pq.push(num);
		}
		cout << sum << " " << pq.top() << "\n";
	}
	return 0;
}