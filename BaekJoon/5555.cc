#include <bits/stdc++.h>
#include <regex>
using namespace std;

string target, ring;
int t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> target;
	regex reg(target);

	cin >> t;
	int sum = 0;

	while (t--) {
		cin >> ring;
		ring += ring;
		if (regex_search(ring, reg))	sum++;
	}

	cout << sum;
	return 0;
}
