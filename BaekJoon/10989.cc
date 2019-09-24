#include <bits/stdc++.h>
using namespace std;
//수 정렬하기 10989	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	//priority_queue<int, vector<int>, greater<int>> pq;

	map<int, int> m;

	while (cnt--) {
		int num;
		cin >> num;
		m[num]++;
	}

	//reverse(map.begin(), map.end());

	for (auto it = m.begin(); it != m.end(); ++it) {
		//int n = it->first;
		for (int i = 0; i < it->second; ++i) {
			cout << it->first << "\n";
		}
	}
	

	return 0;
}