#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;
	int left = 0;

	while (count--) {
		int apple = 0;
		int student = 0;
		cin >> student >> apple;
		left += apple % student;
	}
	cout << left;

	return 0;
}