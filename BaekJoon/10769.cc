#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

string str;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;
	getline(cin, str);

	string happy = ":-)";
	string sad = ":-(";
	bool flag = false;

	for (int i = 0; i + 3 <= str.size(); ++i) {
		if (str.substr(i, 3) == happy) {
			flag = true;
			sum++;
		}
		else if (str.substr(i, 3) == sad) {
			flag = true;
			sum--;
		}
	}

	if (sum == 0) {
		if (!flag)cout << "none";
		else cout << "unsure";
	}
	else if (sum < 0)	cout << "sad";
	else cout << "happy";

	return 0;
}