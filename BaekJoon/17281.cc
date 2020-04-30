#include <bits/stdc++.h>
using namespace std;

bool spot[4];
int player[52][10]; //[이닝][선수번호]
int n ,answer;

int order[10];
vector<int> vec = { 2,3,4,5,6,7,8,9 };

int Hit_Run(int hit) {
    int get_score = 0;

    for (int i = 3; i >= 1; --i) {
        if (spot[i]){
            if (i + hit >= 4) get_score++;
            else spot[i + hit] = true;

            spot[i] = false;
        }
    }

    if (hit == 4) get_score++;
    else spot[hit] = true;

    return get_score;
}

int Game() {
    int score = 0;
    int cnt = 1;

    for (int inning = 1; inning <= n; ++inning) {
        int out = 0;
        memset(spot, false, sizeof(spot));

        while (1) {
            int cur_player = order[cnt];
            cnt = cnt % 9 + 1;

            int hit = player[inning][cur_player];

            if (hit == 0) {
                out++;
                if (out == 3) break;
                continue;
            }

            score += Hit_Run(hit);
        }
    }

    return score;
}

void Make_Order() {

    for (int i = 1; i <= 9; ++i) {
		if (i < 4) order[i] = vec[i - 1];
		else if (i == 4) order[i] = 1;
		else order[i] = vec[i - 2];
    }
}

void Solve() {
    
    do {
        Make_Order();
        answer = max(answer, Game());
    } while (next_permutation(vec.begin(), vec.end()));

    cout << answer << "\n";
}

void Input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int ii = 1; ii <= 9; ++ii) {
            cin >> player[i][ii];
        }
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