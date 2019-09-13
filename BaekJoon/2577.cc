#include <bits/stdc++.h>
using namespace std;

int find_count(const int& num, const int& find_num) {
	int n = 0;
	string number = to_string(num);
	for (int i = 0; i < (int)number.size(); i++) {
		if (number[i] - '0' == find_num) n++;
	}
	return n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n1, n2, n3;
	int result;
	cin >> n1 >> n2 >> n3;
	result = n1 * n2 * n3;

	for (int i = 0; i <= 9; ++i) {
		cout << find_count(result, i) << "\n";
	}

	return 0;
}