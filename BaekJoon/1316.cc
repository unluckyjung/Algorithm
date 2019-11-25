#include<bits/stdc++.h>
#include<regex>
using namespace std;
int ans;

int main() {
	int n; cin >> n;
	while (n--) {
		bool visit[26] = { false, };
		
		string str;	cin >> str;
		int flag = false;

		for (int i = 0; i < (int)str.size(); ++i) {
			char ch = str[i] - 'a';
			if (visit[ch]) {
				flag = true; break;
			}
			visit[ch] = true;
			while (i + 1 < str.size() && str[i] == str[i + 1]) ++i;
		}
		if (!flag)ans++;
	}
	cout << ans;
	return 0;
}