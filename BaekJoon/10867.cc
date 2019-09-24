#include <bits/stdc++.h>
using namespace std;
//10867번 중복 빼고 정렬하기

vector<int> vec;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	while (cnt--) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	int tmp = 100000000;
	for (auto it : vec) {
		if (it != tmp) {
			cout << it << " ";
		}
		tmp = it;
	}

	return 0;
}