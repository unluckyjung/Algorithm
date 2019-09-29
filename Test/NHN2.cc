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
			//리스트에다가 해당 숫자를 넣고
			m[num]++;
			//해당 숫자 등장 빈도수 저장.
		}
		else {
			//dequeue
			if (l.empty()) {
				cout << "-1 ";
			}
			else {

				int MAX = INT_MIN;

				for (auto it = m.begin(); it != m.end(); ++it) {
					MAX = max(MAX, it->second);
					//dequeue인경우, 가장 자주 등장한 숫자의 "빈도수"를 찾음.
				}


				for (auto it = l.begin(); it != l.end(); ++it) {
					if (m[*it] == MAX) {
						//리스트의 앞에서 부터 찾다가, 등장한숫자의 빈도수가 가장 큰 경우
						cout << *it << " ";
						m[*it]--;
						//출력하고, 빈도수를 줄임.
						it = l.erase(it);
						//그리고 해당 노드를 삭제함.
						break;
					}

				}
			}
		}
	}

	return 0;
}