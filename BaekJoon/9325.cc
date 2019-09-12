#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int count;
	cin >> count;
	while (count--) {
		int num;
		int price;
		int sum = 0;
		cin >> price;
		cin >> num;
		while (num--) {
			int option;
			int option_price;
			cin >> option;
			cin >> option_price;
			sum += option * option_price;
		}
		cout << price + sum << "\n";
	}
	return 0;
}