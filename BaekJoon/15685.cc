#include <bits/stdc++.h>
using namespace std;

const int dx[] = { 0, -1, 0 ,1 };
const int dy[] = { 1, 0, -1, 0 };

int curv_n;
bool board[102][102];

int x, y;
int level;
vector<int> vec;

bool square_check(int i, int ii) {
    for (int x = i; x < i + 2; ++x) {
        for (int y = ii; y < ii + 2; ++y) {
            if (board[x][y] == false) return false;
        }
    }
    return true;
}

void get_answer() {
    int answer = 0;
    for (int i = 0; i <= 100; ++i) {
        for (int ii = 0; ii <= 100; ++ii) {
            if (square_check(i,ii)) answer++;
        }
    }
    cout << answer << "\n";
}

void move(int dir) {
    x += dx[dir];
    y += dy[dir];
    board[x][y] = true;
}

void solve() {
    for (int i = 1; i <= level; ++i) {
        int vec_size = vec.size();
        for (int k = vec_size; k >= 1; --k) {
            int dir = (vec[k-1] + 1) % 4;
            move(dir);
            vec.push_back(dir);
        }
    }
}

void init(int dir) {
    vec.clear();
    board[x][y] = true;
    move(dir);
    vec.push_back(dir);
}

void input() {
    cin >> curv_n;
    int dir;
    while (curv_n--) {
        cin >> y >> x >> dir >> level;
        init(dir);
        solve();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    input();
    get_answer();

    return 0;
}