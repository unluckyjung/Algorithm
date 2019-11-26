#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

int t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		string str1, str2;
		cin >> str1 >> str2;
		int sum = 0;
		for (int i = 0; i <(int)str1.size(); ++i) {
			if (str1[i] != str2[i])	sum++;
		}
		cout << "Hamming distance is " << sum << ".\n";
	}

	return 0;
}