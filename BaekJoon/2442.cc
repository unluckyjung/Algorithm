#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int line;
	cin >> line;
	for (int i = 1; i <= line; ++i) {
		for (int blank = line - i; blank >= 1; --blank) {
			cout << " ";
		}
		for (int star = 1; star <= i * 2 - 1; ++star) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}