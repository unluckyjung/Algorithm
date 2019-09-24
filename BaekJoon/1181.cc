#include <bits/stdc++.h>
using namespace std;
//1181 단어 정렬
vector<pair<int, string>>vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int cnt;
	cin >> cnt;

	while (cnt--) {
		string str;
		cin >> str;
		
		int len = str.size();

		vec.push_back({ len, str });

	}
	sort(vec.begin(), vec.end());

	string tmp = "YoonSung";
	for (auto it : vec) {
		if(it.second != tmp) cout << it.second << "\n";
		tmp = it.second;
	}



	return 0;
}