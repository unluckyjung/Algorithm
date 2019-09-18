#include <bits/stdc++.h>
using namespace std;

vector<pair<int, char>> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	int len = str.size();

	for (char i = 'A'; i <= 'Z'; ++i) {
		vec.push_back({ 0, i });
	}

	for (int i = 0; i < len; ++i) {
		char ii = str[i];
		if (ii >= 'a') ii += 'A' - 'a';

		for (auto it = vec.begin(); it != vec.end(); ++it) {
			if (ii == it->second) (it->first)++;
		}
	}

	sort(vec.begin(), vec.end());
	
	//int n = vec.size();
	//cout << vec[n-1].first;	
	//이 방법가능

	//auto it1 = vec.rbegin();
	//auto it2 = ++vec.rbegin();
	//if ((*it1).first == (*it2).first) {
	//	cout << '?'; return 0;
	//}
	//포인터로 접근도 가능



	//auto it1 = vec.rbegin()--;	//--하면 맨뒤에서 더 뒤로감. 메모리 침범오류
	//auto it1 = vec.rbegin()++;	//후위 연산을 하면 rbegin값을 넣고, 증가시킴.
	auto it1 = vec.rbegin();
	auto it2 = ++vec.rbegin();

	//cout << it1->first << "\n";
	//cout << it1->second << "\n";

	//cout << it2->first << "\n";
	//cout << it2->second << "\n";


	if (it1->first == it2->first) {
		cout << '?'; return 0;
	}
	cout << it1->second;
	return 0;
}