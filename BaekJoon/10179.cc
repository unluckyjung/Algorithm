#include<bits/stdc++.h>
#include<regex>
using namespace std;
int T;
double n;

int main() {
	cin.tie(NULL);
	cout << fixed;
	cout.precision(2);
	cin >> T;
	while (T--) {
		double price;	cin >> price;
		cout << "$" << price * 0.8 << '\n';
	}
	return 0;
}