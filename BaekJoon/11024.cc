#include<bits/stdc++.h>
#include<regex>
using namespace std;

int main() {
	regex reg("[0-9]+");
	sregex_iterator end;

	string s;
	int n; cin >> n;
	cin.ignore();

	while (n--) {
		while (getline(cin, s)) {
			int sum = 0;
			sregex_iterator it(s.begin(), s.end(), reg);
			while (it != end) {
				smatch tmp = *it;
				sum += stoi(tmp.str());
				it++;
			}
			cout << sum << '\n';
		}
	}
	return 0;
}