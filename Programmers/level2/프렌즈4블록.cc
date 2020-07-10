#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

vector<string> board;
bool boom[31][31];
int n, m;

const int dx[] = {0, 0, 1, 1};
const int dy[] = {0, 1, 0, 1};

int BoomCntRebase() {
    int cnt = 0;

    for (int ii = 0; ii < m; ++ii) {
        queue<char> q;
        for (int i = n - 1; i >= 0; --i) {
            if (boom[i][ii]) {
                board[i][ii] = '#';
                cnt++;
            }
            if (board[i][ii] == '#') continue;
            q.push(board[i][ii]);
        }
        int qSize = q.size();

        for (int i = 0; i < n - qSize; ++i) {
            q.push('#');
        }

        for (int i = n - 1; i >= 0; --i) {
            board[i][ii] = q.front();
            q.pop();
        }
    }
    return cnt;
}

bool IsFourBoom(int x, int y) {

    char ch = board[x][y];
    for (int dir = 1; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 or nx >= n or ny < 0 or ny >= m) return false;
        if (board[nx][ny] != ch) return false;
    }
    
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (boom[nx][ny]) continue;
        boom[nx][ny] = true;
    }

    return true;
}

bool IsBoom() {
    bool boomFlag = false;
    
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            if (board[i][ii] == '#') continue;
            if (IsFourBoom(i, ii)) boomFlag = true;
        }
    }

    return boomFlag;
}

void BoomReset() {
    memset(boom, false, sizeof(boom));
}

int solution(int mm, int nn, vector<string> b) {
    int answer = 0;
    n = mm;
    m = nn;
    board = b;

    while (1) {
        BoomReset();
        if (!IsBoom()) break;
        answer += BoomCntRebase();
    }

    return answer;
}

int main() {

    vector<string> input{ "CCBDE", "AAADE", "AAABF", "CCBBF" };
    cout << solution(4, 5, input);

    return 0;
}