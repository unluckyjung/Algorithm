#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;
	for (int i = 1; i <= N * 2 - 1; ++i) {
		if (i <= N) {
			for (int j = 1; j <= i; ++j) cout << "*";
			for (int B = N - i; B >= 1; --B) cout << " ";			
			for (int B = N - i; B >= 1; --B) cout << " ";
			for (int j = 1; j <= i; ++j) cout << "*";
		}
		else {
			for (int j = N * 2 - i; j >= 1; --j) cout << "*";
			for (int B = i - N; B >= 1; --B) cout << " ";
			for (int B = i - N; B >= 1; --B) cout << " ";
			for (int j = N * 2 - i; j >= 1; --j) cout << "*";
		}
		cout << "\n";

	}
	return 0;
}