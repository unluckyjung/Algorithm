#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//clock_t start, stop;
	//start = clock();
	////function
	//stop = clock();

	vector<int> vec;
	int cnt;
	cin >> cnt;
	while (cnt--) {
		int num;
		cin >> num;
		if (num == 0) vec.pop_back();
		else vec.push_back(num);
	}
	
	int sum = 0;
	for (const int &i : vec) sum += i;
	cout << sum;

	return 0;
}