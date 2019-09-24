#include <bits/stdc++.h>
using namespace std;
//11651 좌표 정렬하기2
vector<pair<int, int>>vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int cnt;
	cin >> cnt;

	while (cnt--) {
		int num1, num2;
		cin >> num1 >> num2;
		vec.push_back({ num2,num1 });
	}
	sort(vec.begin(), vec.end());

	for (auto it : vec) {
		cout << it.second << " " << it.first << "\n";
	}

	return 0;
}