#include <bits/stdc++.h>
using namespace std;

int score[33] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,22,24,28,27,26,25,30,35};
bool visit[32];

int knight_spot[4];
int dice[10];
int order[10];

const int A = 0, B = 1, C = 2, D = 3;
const int fin = 100;

int answer;

vector<int>table[41] = {
{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
{0,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
{0,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
{0,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
{0,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},

{0,21,22,23,29,30,31,20},

{0,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
{0,8,9,10,11,12,13,14,15,16,17,18,19,20},
{0,9,10,11,12,13,14,15,16,17,18,19,20},
{0,10,11,12,13,14,15,16,17,18,19,20},

{0,24,25,29,30,31,20},

{0,12,13,14,15,16,17,18,19,20},
{0,13,14,15,16,17,18,19,20},
{0,14,15,16,17,18,19,20},
{0,15,16,17,18,19,20},

{0,26,27,28,29,30,31,20},

{0,17,18,19,20},
{0,18,19,20},
{0,19,20},
{0,20},

{0},

{0,22,23,29,30,31,20},
{0,23,29,30,31,20},
{0,29,30,31,20},

{0,25,29,30,31,20},
{0,29,30,31,20},

{0,27,28,29,30,31,20},
{0,28,29,30,31,20},
{0,29,30,31,20},

{0,30,31,20},
{0,31,20},
{0,20},

};

int Move() {
	int sum = 0;

	for (int i = 0; i < 10; ++i) {
		int knight = order[i];
		int cur_spot = knight_spot[knight];
		int move_dist = dice[i];

		if (cur_spot == fin) continue;

		if (move_dist >= (int)table[cur_spot].size()) {
			visit[cur_spot] = false;
			knight_spot[knight] = fin;
		}
		else {
			int nxt_spot = table[cur_spot][move_dist];

			if (visit[nxt_spot]) return 0;
			visit[nxt_spot] = true;
			knight_spot[knight] = nxt_spot;

			sum += score[nxt_spot];
			visit[cur_spot] = false;
		}

	}
	return sum;
}

void Dfs(int dice_n) {

	if (dice_n == 10) {

		memset(visit, false, sizeof(visit));
		memset(knight_spot, false, sizeof(knight_spot));

		answer = max(answer, Move());

		return;
	}

	order[dice_n] = A;
	Dfs(dice_n + 1);

	order[dice_n] = B;
	Dfs(dice_n + 1);

	order[dice_n] = C;
	Dfs(dice_n + 1);

	order[dice_n] = D;
	Dfs(dice_n + 1);

}

void Solve() {
    Dfs(0);

	cout << answer << "\n";
}

void Input() {
    for (int i = 0; i < 10; ++i) {
        cin >> dice[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

	Input();
	Solve();


    return 0;
}