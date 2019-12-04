#include<bits/stdc++.h>

using namespace std;

int X, Y;
int Y_C, Y_D;
int P;

int x_price, y_price;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> X >> Y >> Y_C >> Y_D >> P;

	x_price = X * P;
	y_price = Y;

	if (P > Y_C) {
		y_price += (P - Y_C)* Y_D;
	}

	cout << min(x_price, y_price);
	return 0;
}