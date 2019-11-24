#include<bits/stdc++.h>
#include<regex>
using namespace std;

int T;
int main() {
	cin >> T;
	regex reg("[0-9]+");
	sregex_iterator end;
	while (T--) {
		string s;	cin >> s;
		if (s == "P=NP") {
			cout << "skipped\n";
			continue;
		}
		int sum = 0;
		sregex_iterator it(s.begin(), s.end(), reg);
		while (it != end) {
			smatch tmp = *it;
			sum += stoi(tmp.str());
			it++;
		}
		cout << sum << '\n';
	}
	return 0;
}