#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int Class;
	cin >> Class;


	for(int i = 1; i<=Class; ++i) {
		int student;
		cin >> student;

		vector<int> vec;

		while(student--) {
			int score;
			cin >> score;
			vec.push_back(score);
		}

		sort(vec.begin(), vec.end(), greater<int>());

		int len = vec.size();
		int gap = -1;

		for (int i = 1; i < len; ++i) {
			gap = max(gap, vec[i - 1]-vec[i]);
		}
		printf("Class %d\n", i);
		printf("Max %d, Min %d, Largest gap %d\n", vec.front(), vec.back(), gap);
	}

	return 0;
}