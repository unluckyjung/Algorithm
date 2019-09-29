#include<bits/stdc++.h>
using namespace std;

int n;
list <int> l;
map <int, int> m;
vector<int> vec;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "enqueue") {
			int num;
			cin >> num;
			l.push_back(num);
			m[num]++;
		}
		else {
			if (l.empty()) {
				cout << "-1 ";
			}
			else {
				int MAX = INT_MIN;

				for (auto it = m.begin(); it != m.end(); ++it) {
					MAX = max(MAX, it->second);
				}


				for (auto it = l.begin(); it != l.end(); ++it) {
					if (m[*it] == MAX) {
						cout << *it << " ";
						//vec.push_back(*it);
						m[*it]--;
						it = l.erase(it);
						break;
					}

				}
			}
		}
	}

	//for (auto it : vec) {
	//	cout << it << " ";
	//}
	return 0;
}