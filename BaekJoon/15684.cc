#if 01

#include <bits/stdc++.h>
using namespace std;

bool ladder[32][12];

int n, m, h;
int answer = INT_MAX;

bool check() {
    for (int ladder_num = 1; ladder_num <= n; ++ladder_num) {
        int cur_spot = ladder_num;
        for (int height = 1; height <= h; ++height) {
            if (ladder[height][cur_spot])  cur_spot++;
            else if (ladder[height][cur_spot - 1]) cur_spot--;
        }
        if (cur_spot != ladder_num) return false;
    }
    return true;
}

bool add_ladder(int height, int ladder_num) {
    for (int i = -1; i <= 1; ++i) {
        if (ladder[height][ladder_num + i]) return false;
    }
    return true;
}


void dfs(int height, int ladder_num, int cur) {
    if (cur >= answer) return;
    if (check()) {
        answer = cur;
        return;
    }

    if(cur == 3) return;

	for (int a = height; a <= h; ++a) {
		for (int b = ladder_num; b <= n-1; ++b) {

			if (!add_ladder(a, b))continue;
			ladder[a][b] = true;
			dfs(a, b + 1, cur + 1);
			ladder[a][b] = false;

		}
		ladder_num = 1;
	}

}

void solve() {
    dfs(1, 1, 0);
    if (answer == INT_MAX)   cout << -1 << "\n";
    else cout << answer << "\n";
}

void input() {
    cin >> n >> m >> h;

    int a, b;
    while (m--) {
        cin >> a >> b;
        if (add_ladder(a, b)) ladder[a][b] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}

#else

#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int answer = INT_MAX;
bool ladder[31][11];

int get_finised_spot(int ladder_num) {
	int cur_spot = ladder_num;

	for (int height = 0; height <= h; ++height) {
        if (ladder[height][cur_spot]) cur_spot++;
        else if(ladder[height][cur_spot - 1]) cur_spot--;
	}
	return cur_spot;
}

bool can_go() {
    for (int ladder_num = 1; ladder_num <= n; ++ladder_num) {
        if (ladder_num != get_finised_spot(ladder_num)) return false;
    }
    return true;
}

void dfs(int ladder_cnt, int a, int b) {
    if (ladder_cnt > 3 or ladder_cnt >= answer) return;
    if (can_go()) {
        answer = ladder_cnt;
        return;
    }

    for (int i = a; i <= h; ++i) {
        for (int ii = b; ii <= n - 1; ++ii) {
            if (ladder[i][ii])continue;
            if (ladder[i][ii-1])continue;
            if (ladder[i][ii+1])continue;

            
            ladder[i][ii] = true;
            dfs(ladder_cnt + 1, i, ii + 1);
            ladder[i][ii] = false;
        }
        b = 1;
    }
}

void solve() {
    dfs(0, 1, 1);
    if (answer > 3)cout << -1;
    else cout << answer;
}

void input() {
    cin >> n >> m >> h;

    int a, b;
    while (m--) {
        cin >> a >> b;
        ladder[a][b] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}

#endif