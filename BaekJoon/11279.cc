#include<bits/stdc++.h>

using namespace std;

int n;
priority_queue<int, vector<int>, less<int>> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	
	while (n--) {
		int cmd;	cin >> cmd;
		if (cmd == 0) {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else cout << 0 << '\n';
		}
		else
		{
			pq.push(cmd);
		}
	}
	return 0;
}