#include<bits/stdc++.h>
using namespace std;
//백준 입실관리 5524
//https://www.acmicpc.net/problem/5524

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	while (n--) {
		string str;
		cin >> str;
		//for (int i = 0; i < (int)str.size(); ++i) {
		//	str[i] = tolower(str[i]);
		//}
		//혹은
		transform(str.begin(), str.end(), str.begin(), (int(*)(int))tolower);
		cout << str <<"\n";
	}

	return 0;
}