#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 5;
	int drink = INT_MAX;

	while (cnt--) {
		int price;
		cin >> price;

		if (cnt < 2) drink = min(drink, price);
		else vec.push_back(price);
	}

	sort(vec.begin(), vec.end());

	cout << *vec.begin() + drink - 50;
	return 0;
}