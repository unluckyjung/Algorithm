#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)	break;

		if ((int)pow(a, 2) == ((int)pow(b, 2) + (int)pow(c, 2))) {
			cout << "right\n";
		}
		else if ((int)pow(b, 2) == ((int)pow(a, 2) + (int)pow(c, 2))) {
			cout << "right\n";
		}
		else if ((int)pow(c, 2) == ((int)pow(a, 2) + (int)pow(b, 2))) {
			cout << "right\n";
		}
		else cout << "wrong\n";

	}

	return 0;
}