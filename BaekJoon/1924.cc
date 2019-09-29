#include<bits/stdc++.h>
using namespace std;
//백준 1924

int x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y;

	for (int i = 2; i <= x; ++i) {
		if (i == 2 or i == 4 or i == 6 or i == 8 or i == 9 or i == 11)
			y += 31;
		else if (i == 5 or i == 7 or i == 10 or i == 12)
			y += 30;
		else if (i == 3)
			y += 28;
	}
	
	y = y % 7;
	if (y == 0)
		cout << "SUN";
	else if (y == 1)
		cout << "MON";
	else if (y == 2)
		cout << "TUE";
	else if (y == 3)
		cout << "WED";
	else if (y == 4)
		cout << "THU";
	else if (y == 5)
		cout << "FRI";
	else if (y == 6)
		cout << "SAT";


	return 0;
}