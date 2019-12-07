#include<bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		if (n1 == 0 && n2 == 0 && n3 == 0) {
			break;
		}

		if (n2 - n1 == n3 - n2) {
			int dif = n2 - n1;
			cout << "AP " << n3 + dif << "\n";
		}
		else {
			cout << "GP " << n3 * (n3/n2) << "\n";
		}

	}

	return 0;
}