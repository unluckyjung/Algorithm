#include<bits/stdc++.h>
using namespace std;

int main() {
	stack<int> pipe;
	string s;
	cin >> s;
	int count = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			pipe.push(i);
		else if (s[i] == ')') {
			if (pipe.top() + 1 == i) {
				pipe.pop();
				count += pipe.size();
			}
			else {
				pipe.pop();
				count++;
			}
		}
	}
	cout << count;
	return 0;
}