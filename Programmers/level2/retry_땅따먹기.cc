#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100000][4];

int solution(vector<vector<int> > land)
{
	int answer = 0;
	dp[0][0] = land[0][0];
	dp[0][1] = land[0][1];
	dp[0][2] = land[0][2];
	dp[0][3] = land[0][3];

	for (int i = 1; i < (int)land.size(); ++i) {
		for (int ii = 0; ii < 4; ++ii) {
			int add = 0;
			for (int index = 0; index < 4; ++index) {
				if (ii == index)continue;
				dp[i][ii] = max(dp[i][ii], dp[i - 1][index] + land[i][ii]);
				answer = max(answer, dp[i][ii]);
			}
		}
	}
	return answer;
}



int solution2(vector<vector<int> > land)
{
	int answer = 0;

	for (int i = 0; i < 4; ++i) {
		dp[0][i] = land[0][i];
		answer = max(answer, land[0][i]);
	}
	

	for (int i = 1; i < land.size(); ++i) {
		
		for (int ii = 0; ii < 4; ++ii) {
			int MAX = 0;
			for (int dp_idx = 0; dp_idx < 4; ++dp_idx) {
				if (ii == dp_idx) continue;
				MAX = max(MAX, dp[i-1][dp_idx]);
				//dp[i][ii] = max(dp[i][ii], dp[i-1][dp_idx] + land[i][ii]);
				//answer = max(answer, dp[i][ii]);
			}
			dp[i][ii] = land[i][ii] + MAX;
			answer = max(answer, dp[i][ii]);
		}
	}
	return answer;
}