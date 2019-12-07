#include<bits/stdc++.h>

using namespace std;

int n0, n1, n2, n3, n4;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt = 1;
	while (1) {
		
		cin >> n0;
		if (n0 == 0) break;

		n1 = n0 * 3;

		bool iseven = false;
		if (n1 %2 == 0) {
			n2 = n1 / 2;
			iseven = true;
		}
		else {
			n2 = (n1 + 1) / 2;
		}

		n3 = n2 * 3;
		n4 = n3 / 9;

		if (iseven) {
			cout << cnt << ". " << "even " << n4 <<"\n";
		}
		else {
			cout << cnt << ". " << "odd " << n4 <<"\n";
		}
		cnt++;
	}

	return 0;
}