#include<iostream>

using namespace std;

int q;
long long a, b, n, s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> q;
	while (q--) {
		cin >> a >> b >> n >> s;

		bool no = true;
		if (s % n <= b && s <= a * n + b)	no = false;

		if (no) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}