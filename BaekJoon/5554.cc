#include<bits/stdc++.h>
#include<regex>
using namespace std;

int sum;
int main() {
	int n;
	for (int i = 0; i < 4; ++i) {
		cin >> n;
		sum += n;
	}

	cout << sum / 60 << '\n';
	cout << sum % 60;
	return 0;
}