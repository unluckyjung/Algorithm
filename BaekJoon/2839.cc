#include<bits/stdc++.h>

using namespace std;

int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	int five_bag = 0;
	int three_bag = 0;

	while (1) {

		if (N <= 2) {
			cout << -1;
			return 0;
		}

		five_bag = N / 5;
		int left_bag = N % 5;

		if (left_bag) {
			if ((left_bag % 3) == 0) {
				cout << five_bag + three_bag + 1;
				return 0;
			}
			else {
				N = N - 3;
				three_bag++;
			}
		}
		else {
			cout << five_bag + three_bag;
			return 0;
		}
	}
	return 0;
}