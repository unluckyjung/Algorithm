#include<bits/stdc++.h>

using namespace std;

int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	vector<int> cheat;
	for (int student = 1; student <= N; ++student) {
		int score = 0;

		for (int exam = 1; exam <= 10; ++exam) {
			int student_ans;	cin >> student_ans;
			int ans = ((exam - 1) % 5) + 1;
			if (student_ans == ans)	score++;
		}

		if (score == 10)	cheat.push_back(student);
	}

	for (int i : cheat) {
		cout << i << "\n";
	}
	return 0;
}