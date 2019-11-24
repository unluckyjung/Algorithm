#include<bits/stdc++.h>
using namespace std;

int n1, n2;
int main() {
	cin.tie(NULL);
	cin >> n1 >> n2;
	while (n1 != 0 && n2 !=0) {
		cout << n1 / n2 << " " << n1 % n2 << " / " << n2 << '\n';
		cin >> n1 >> n2;
	}
	return 0;
}