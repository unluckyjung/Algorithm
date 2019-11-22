#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[1001][1001];

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int row = board.size();
	int col = board[0].size();

	for (int i = 0; i < row; ++i) {
		for (int ii = 0; ii < col; ++ii) {

			if (i == 0 || ii == 0) {
				if (board[i][ii] == 1) {
					dp[i][ii] = 1;	answer = max(answer, dp[i][ii]);
				}
				continue;
			}

			if (board[i][ii]) {
				dp[i][ii] = min({ dp[i - 1][ii], dp[i][ii - 1], dp[i - 1][ii - 1] }) + 1;
				answer = max(answer, dp[i][ii]);
			}
		}
	}

	answer *= answer;
	return answer;
}