#include<bits/stdc++.h>
using namespace std;
//백준 2048 2009년

int x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> y >> x;

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
		cout << "Wednesday";
	else if (y == 1)
		cout << "Thursday";
	else if (y == 2)
		cout << "Friday";
	else if (y == 3)
		cout << "Saturday";
	else if (y == 4)
		cout << "Sunday";
	else if (y == 5)
		cout << "Monday";
	else if (y == 6)
		cout << "Tuesday";


	return 0;
}