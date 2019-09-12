#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 3;
	while (count--) {
		int Try = 4;
		int sum = 0;
		while (Try--) {
			int n;
			cin >> n;
			sum += n;
		}
		switch (sum) {
		case 0: cout << "D" << "\n"; break;
		case 1: cout << "C" << "\n"; break;
		case 2: cout << "B" << "\n"; break;
		case 3: cout << "A" << "\n"; break;
		case 4: cout << "E" << "\n"; break;
		default: break;
		}
	}
	return 0;
}