#include <bits/stdc++.h>
using namespace std;

int main()
{
	int count;
	double MAX = -123123;
	cin >> count;
	vector<double> v;

	double sum = 0;
	while (count--) {
		double score;
		cin >> score;
		v.push_back(score);
		MAX = max(MAX, score);
	}
	
	for (const auto &i : v) {
		sum += i / MAX * 100;
	}

	printf("%.3f", sum/(int)v.size());
	return 0;
}