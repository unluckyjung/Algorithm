#include<bits/stdc++.h>
using namespace std;
//백준 3059 등장하지 않는 문자의 합
//https://www.acmicpc.net/problem/3059

int sum;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (char i = 'A'; i <= 'Z'; ++i) {
		sum += (int)i;
	}

	int cnt; cin >> cnt;

	while (cnt--) {
		string str; cin >> str;
		int ans = sum;
        sort(str.begin(), str.end());   //이거없으면 틀리는데 이유모르겠음.
		str.erase(unique(str.begin(), str.end()), str.end());
		//중복되는놈 삭제.
		for (int i = 0; i < (int)str.size(); ++i) {
			ans -= (int)str[i];
		}
		cout << ans << "\n";
	}
	return 0;
}