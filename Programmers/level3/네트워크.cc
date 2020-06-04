#include<bits/stdc++.h>
using namespace std;


vector<int> node[202];
bool visit[202];

void dfs(int com) {
    for (auto& nxt_com : node[com]) {
        if (visit[nxt_com]) continue;
        visit[nxt_com] = true;
        dfs(nxt_com);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int cur_computer = 0; cur_computer < n; ++cur_computer) {
        for (int other_computer = 0; other_computer < n; ++other_computer) {
            if (computers[cur_computer][other_computer]) {
                node[cur_computer].push_back(other_computer);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (visit[i]) continue;
        visit[i] = true;
        answer++;
        dfs(i);
    }
    return answer;
}

int main() {

    int n = 3;
    vector<vector<int>> vec{ {1, 1, 0}, { 1, 1, 0 }, { 0, 0, 1 }};
    cout << solution(n, vec);
    return 0;
}