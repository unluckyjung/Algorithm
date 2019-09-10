#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			cout << " ";
		}
		for (int z = 0; z <= i; ++z) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}