#include<bits/stdc++.h>
#include<regex>
using namespace std;

int main() {
	cin.tie(NULL);
	string n1, n2;
	string ans;
	cin >> n1 >> n2;
	while (!n1.empty() || !n2.empty()) {
		int num1 = 0, num2 = 0;
		if (!n1.empty()) {
			num1 += n1.back() - '0';
			n1.pop_back();
		}
		if (!n2.empty()) {
			num2 += n2.back() - '0';
			n2.pop_back();
		}

		ans = to_string(num1 + num2) + ans;
	}
	cout << ans;
	return 0;
}