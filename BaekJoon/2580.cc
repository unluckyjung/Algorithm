#include<bits/stdc++.h>
#define pp pair<int, int>
using namespace std;

int n = 9;
int board[10][10];

bool row[10][11];
bool col[10][11];
bool box[10][11];

int blank;
stack<pair<int, int> > STACK;

int find_box_num(int nx, int ny) {
	int box_num = 0;
	if (nx < 3) {
		box_num = 0;
		if (ny < 3) box_num;
		else if (ny < 6) box_num += 1;
		else if (ny < 9) box_num += 2;
	}
	else if (nx < 6) {
		box_num = 3;
		if (ny < 3) box_num;
		else if (ny < 6) box_num += 1;
		else if (ny < 9) box_num += 2;
	}
	else if (nx < 9) {
		box_num = 6;
		if (ny < 3) box_num;
		else if (ny < 6) box_num += 1;
		else if (ny < 9) box_num += 2;
	}

	return box_num;
}

bool box_check(int nx, int ny, int idx) {
	int box_num = find_box_num(nx, ny);
	return box[box_num][idx];
}

void box_set(int nx, int ny, int value, bool b) {
	int box_num = find_box_num(nx, ny);
	box[box_num][value] = b;
}

void output() {
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			cout << board[i][ii] << " ";
		}
		cout << "\n";
	}
}

void dfs(int black_cnt) {
	if (black_cnt == 0) {
		output();
		exit(0);
	}

	while (!STACK.empty()) {
		pp cur = STACK.top();	STACK.pop();

		int nx = cur.first;
		int ny = cur.second;

		for (int i = 1; i <= 9; ++i) {
			if (row[nx][i])continue;
			if (col[ny][i])continue;
			if (box_check(nx, ny, i))continue;

			row[nx][i] = true;
			col[ny][i] = true;
			box_set(nx, ny, i, true);
			board[nx][ny] = i;

			dfs(black_cnt - 1);

			row[nx][i] = false;
			col[ny][i] = false;
			box_set(nx, ny, i, false);
			board[nx][ny] = 0;
		}
		STACK.push(cur);
		return;
	}
}

void solve() {
	dfs(blank);
}

void input() {
	int value;
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			cin >> value;
			board[i][ii] = value;

			if (value == 0) {
				STACK.push({ i,ii });
				blank++;
			}
			else {
				row[i][value] = true;
				col[ii][value] = true;
				box_set(i, ii, value, true);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	input();
	solve();

	return 0;
}