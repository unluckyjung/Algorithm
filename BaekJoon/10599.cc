#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int a, b, c, d;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0)break;
		cout << c - b << " " << d - a << "\n";
	}
	return 0;
}