#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//1919 에너그램
	string str1, str2;
	map<char, int> m1, m2;

	cin >> str1 >> str2;
	for (int i = 0; i < (int)str1.size(); ++i) {
		m1[str1[i]]++;
	}

	for (int i = 0; i < (int)str2.size(); ++i) {
		m2[str2[i]]++;
	}

	int sum = 0;
	for (char i = 'a'; i <= 'z'; ++i) {
		sum += abs(m1[i] - m2[i]);
	}

	cout << sum;
	return 0;
}