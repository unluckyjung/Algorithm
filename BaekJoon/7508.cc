#include<bits/stdc++.h>
using namespace std;
//백준 7508 덩치
//https://www.acmicpc.net/problem/7508

vector<pair<int, int>> p;

int ranking[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt; cin >> cnt;
	for(int i = 0 ; i< cnt; ++i){
		int n1, n2; cin >> n1 >> n2;
		p.push_back({ n1,n2 });
	}


	for (int i = 0; i < cnt; ++i) {
		for (int ii = 0; ii < cnt; ++ii) {
			if (p[i].first < p[ii].first and p[i].second < p[ii].second) {
				ranking[i]++;
			}
		}
	}

	for (int i = 0; i < cnt; ++i) {
		cout << ranking[i]+1 << " ";
	}

	return 0;
}