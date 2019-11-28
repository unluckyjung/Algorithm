#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	deque<int> dq;
	int item;
	cin >> N >> M;
	while (N--) {
		cin >> item;
		dq.push_back(item);
	}

	sort(dq.begin(), dq.end());

	int ans = 0;
	while (1) {
		if (dq.size() <= 1)break;

		int sum = dq.front() + dq.back();
		if (M == sum) {
			ans++;
			dq.pop_back();	dq.pop_front();
		}
		else if (sum < M)	dq.pop_front();
		else if (sum > M)	dq.pop_back();
	}

	cout << ans;
	return 0;
}