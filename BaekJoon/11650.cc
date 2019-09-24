#include <bits/stdc++.h>
using namespace std;
//11650 좌표 정렬하기.
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
		vec.push_back({ num1,num2 });
	}
	sort(vec.begin(), vec.end());

	for (auto it : vec) {
		cout << it.first << " " << it.second << "\n";
	}

	return 0;
}