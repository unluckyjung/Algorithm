#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool visit[1000];


int solution(vector<vector<int>> baseball) {
	int answer = 0;

	string numbers = "123456789";

	do {
		string str = numbers.substr(0, 3);
		if (visit[stoi(str)])continue;
		visit[stoi(str)] = true;

		int flag = true;
		for (int i = 0; i < (int)baseball.size(); ++i) {
			string num = to_string(baseball[i][0]);
			int strike = baseball[i][1];
			int ball = baseball[i][2];

			//cout << strike << " " << ball << " ";

			int s = 0, b = 0;
			for (int ii = 0; ii < 3; ++ii) {
				if (str[ii] == num[ii])	s++;
				else {
					if (num.find(str[ii]) != -1)	b++;
				}
			}
			if (s != strike || b != ball) {
				flag = false; break;
			}
		}
		if (flag) answer++;

	} while (next_permutation(numbers.begin(), numbers.end()));

	return answer;
}