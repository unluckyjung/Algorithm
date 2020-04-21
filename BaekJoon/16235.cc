#include <bits/stdc++.h>
using namespace std;

struct land {
    deque<int> tree_list;
    int food = 0;
    int parent_num = 0;
};

land board[12][12];
int robot[12][12];

int n, m, k;
const int dx[] = { -1,-1,-1,0,0,1,1,1 };
const int dy[] = { -1,0,1,-1,1,-1,0,1 };

int get_answer() {
    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        for (int ii = 1; ii <= n; ++ii) {
            sum += board[i][ii].tree_list.size();
        }
    }
    return sum;
}

void fall_winter(const int &i, const int &ii) {
    board[i][ii].food += robot[i][ii];
    if (board[i][ii].parent_num == 0)return;


    for (int dir = 0; dir < 8; ++dir) {
        int nx = i + dx[dir];
        int ny = ii + dy[dir];

        if (nx <= 0 or nx > n or ny <= 0 or ny > n)continue;

        for(int k = 0 ; k< board[i][ii].parent_num; ++k){
            board[nx][ny].tree_list.push_back(1);
        }
    }

    board[i][ii].parent_num = 0;
}

void spring_summer(const int &i, const int &ii) {

    int save_food = 0;

    int dq_size = board[i][ii].tree_list.size();
    sort(board[i][ii].tree_list.rbegin(), board[i][ii].tree_list.rend());


    while (dq_size--) {
        int cur_tree = board[i][ii].tree_list.back();
        board[i][ii].tree_list.pop_back();

        if (cur_tree <= board[i][ii].food) {
            board[i][ii].food -= cur_tree;

            cur_tree++;
            board[i][ii].tree_list.push_front(cur_tree);
            if (cur_tree % 5 != 0) continue;
            board[i][ii].parent_num++;
        }
        else {
            save_food += cur_tree / 2;
        }
    }

    board[i][ii].food += save_food;
}

void solve() {

    while (k--) {

        for (int i = 1; i <= n; ++i) {
            for (int ii = 1; ii <= n; ++ii) {
                spring_summer(i, ii);
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int ii = 1; ii <= n; ++ii) {
                fall_winter(i, ii);
            }
        }
    }
    cout << get_answer() << "\n";
}

void input() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
        for (int ii = 1; ii <= n; ++ii) {
            cin >> robot[i][ii];
            board[i][ii].food += 5;
        }
    }

    int x, y, tree_age;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> tree_age;

        board[x][y].tree_list.push_back(tree_age);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}