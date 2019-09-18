#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int len = (int)str.size();
	
	for (int i = 0; i < len; ++i) {
		int num;
		num = str[i] - '0';
		vec.push_back(num);
	}
	
	sort(vec.begin(), vec.end(), greater<int>());
	
	for (int i : vec)
		cout << i;
	return 0;
}