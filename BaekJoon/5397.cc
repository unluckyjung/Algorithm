#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	while (cnt--) {
		string cmd;
		cin >> cmd;
		int len = (int)cmd.size();
		list<char> l;

		auto it = l.begin();
		for (int i = 0; i < len; ++i) {
			if (cmd[i] == '<') {
				if (it != l.begin())it--;//continue;
				//it--;
			}
			else if (cmd[i] == '>') {
				if (it != l.end())it++; //continue;
				//it++;
			}
			else if (cmd[i] == '-') {
				if (it != l.begin()) it = l.erase(--it); //continue;
				//it = l.erase(--it);
			}
			else {
				l.insert(it, cmd[i]);
			}
		}
		for (auto ans : l)
			cout << ans;
		cout << "\n";
	}

	return 0;
}