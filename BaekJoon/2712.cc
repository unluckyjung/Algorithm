#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << fixed;
	cout.precision(4);

	int t;	cin >> t;
	while (t--) {
		double n;
		string unit;
		cin >> n >> unit;
		if (unit == "kg") {
			cout << n * 2.2046 << " " << "lb\n";
		}
		else if (unit == "lb") {
			cout << n * 0.4536 << " " << "kg\n";
		}
		else if (unit == "l") {
			cout << n * 0.2642 << " " << "g\n";
		}
		else if (unit == "g") {
			cout << n * 3.7854 << " " << "l\n";
		}
	}

	return 0;
}
