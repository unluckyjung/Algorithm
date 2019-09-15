#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> d;

	int cnt;
	cin >> cnt;

	string cmd;
	while (cnt--) {
		cin >> cmd;
		if (cmd == "push_front") {
			int n;
			cin >> n;
			d.push_front(n);
		}
		if (cmd == "push_back") {
			int n;
			cin >> n;
			d.push_back(n);
		}
		if (cmd == "pop_front") {
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.front() << "\n";
				d.pop_front();
			}
		}
		if (cmd == "pop_back") {
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.back() << "\n";
				d.pop_back();
			}
		}
		if (cmd == "size") {
			cout << d.size() << "\n";
		}
		if (cmd == "empty") {
			if (d.empty()) cout << "1\n";
			else cout << "0\n";
		}
		if (cmd == "front") {
			if (d.empty()) cout << "-1\n";
			else cout << d.front() << "\n";
		}
		if (cmd == "back") {
			if (d.empty()) cout << "-1\n";
			else cout << d.back() << "\n";
		}
	}
	return 0;
}