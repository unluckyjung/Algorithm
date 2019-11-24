#include<bits/stdc++.h>
#include<regex>
using namespace std;

int sum;
int n;
int main() {
	cin.tie(NULL);

	while (cin >> n) {
		sum += n;
	}
	cout << sum;
	return 0;
}