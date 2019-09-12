#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;
	for (int i = 0; i < N * 2 - 1; ++i) {
		if (i < N) {
			for (int B = i; B >= 1; B--) cout << " ";
			for (int j = (N - i) * 2 - 1; j >= 1; --j) cout << "*";
		}
		else {
			for (int B = N * 2 - 2 - i; B >= 1; --B) cout << " ";
			for (int j = (i + 2 - N) * 2 - 1; j >= 1; --j) cout << "*";
		}
		cout << "\n";

	}
	return 0;
}