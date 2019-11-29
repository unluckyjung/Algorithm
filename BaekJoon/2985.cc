#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;
	if (b + c == a) { cout << a << "=" << b << "+" << c; }
	else if (b - c == a) { cout << a << "=" << b << "-" << c; }
	else if (b * c == a) { cout << a << "=" << b << "*" << c; }
	else if (b / c == a) { cout << a << "=" << b << "/" << c; }
	else if (a + b == c) { cout << a << "+" << b << "=" << c; }
	else if (a - b == c) { cout << a << "-" << b << "=" << c; }
	else if (a * b == c) { cout << a << "*" << b << "=" << c; }
	else if (a / b == c) { cout << a << "/" << b << "=" << c; }

	return 0;
}
