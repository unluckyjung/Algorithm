#include<bits/stdc++.h>
#include<regex>
using namespace std;
int sum;

int main() {
	regex reg("[0-9]+");
	sregex_iterator end;

	string s;
	string str;
	while (getline(cin, s)) {
		str += s;
	}

	sregex_iterator it(str.begin(), str.end(), reg);

	while (it != end) {
		smatch tmp = *it;
		sum += stoi(tmp.str());
		it++;
	}
	cout << sum;
	return 0;
}