#include<bits/stdc++.h>
using namespace std;

int m;
int cup[4] = { 0,1,2,3 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		swap(cup[x], cup[y]);
	}
	for (int i = 1; i < 4; ++i) {
		if (cup[i] == 1) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}