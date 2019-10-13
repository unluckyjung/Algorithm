#include <bits/stdc++.h>
using namespace std;
//백준 1018 체스판 다시 칠하기
//https://www.acmicpc.net/problem/1018

vector<string> board;
int n, m;
int MIN = INT_MAX;

void cal_num(int row, int col) {
	int nx = row + 8;
	int ny = col + 8;

	char tmp = board[row][col];
	int cnt = 0;
	for (int i = row; i < nx; ++i) {
		for (int ii = col; ii < ny; ++ii) {
			if ((i - row) & 1) {
				if ((ii - col) & 1) {
					if (board[i][ii] != tmp) cnt++;
				}
				else {
					if (board[i][ii] == tmp) cnt++;
				}
			}
			else {
				//열이 짝수이고
				if ((ii - col) & 1) {
					//행이 홀수일때
					if (board[i][ii] == tmp) cnt++;
					//같다면 증가시킴.
				}
				else {
					//행이 짝수일때
					if (board[i][ii] != tmp) cnt++;
					//다르다면 증가시킴
				}
			}
		}
	}
	MIN = min(MIN, cnt);

	//체스판이 회전 되는 경우도 따져봐야한다.
	//흑, 백의 칸이 바뀌기 때문에 최대 값인 64에서 바뀌기 전의 최솟값을 같이 계산한다.
	MIN = min(MIN, 64 - cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string str; cin >> str;
		board.push_back(str);
	}
	for (int i = 0; i <= n - 8; ++i) {
		for (int ii = 0; ii <= m - 8; ++ii) {
			cal_num(i, ii);
		}
	}

	cout << MIN;
	return 0;
}