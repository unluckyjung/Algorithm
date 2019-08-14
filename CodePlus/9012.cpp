#include<bits/stdc++.h>
using namespace std;
//stack 문제.
string valid(string s) {
	int count = 0;
	for (unsigned i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			count++;
		else
			count--;

		if (count < 0)
			return "NO";
	}
	if (count == 0) //unsigned를 주면 이상한거 들어갓을때 -나와도 정답처리되어버림.
		return "YES";
	else
		return "NO";
}

int main() {
	//stack<int> s;
	unsigned count;
	scanf("%u", &count);

	while (count--) {
		string s;
		cin >> s;
		cout << valid(s) << '\n';
	}
	return 0;
}