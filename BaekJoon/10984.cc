#include <bits/stdc++.h>
using namespace std;

int main()
{
	int semester;
	int subject_num;
	int score;
	double grade;


	cin >> semester;
	while (semester--) {
		vector<pair<int, double>> v;

		cin >> subject_num;

		while (subject_num--) {
			cin >> score >> grade;
			v.push_back(make_pair(score, grade));
		}
		int sum = 0;
		double grade_sum = 0;
		int count = 0;

		for (auto& i : v) {
			sum += i.first;
			grade_sum += i.first*i.second;
			count++;
		}
		printf("%d %.1f\n", sum, grade_sum / sum);
	}
	return 0;
}