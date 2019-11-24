#include<bits/stdc++.h>
#include<regex>
using namespace std;

string s;
int sum;

int main() {
	cin.tie(NULL);
	cin >> s;

	regex reg("[0-9]+");
	sregex_iterator end;

	sregex_iterator it(s.begin(), s.end(), reg);

	while (it != end) {
		smatch num = *it;
		sum += stoi(num.str());
		it++;
	}
	
	cout << sum;
	return 0;
}