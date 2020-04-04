#include <bits/stdc++.h>
using namespace std;

string cmp_str, name;
int answer;
int cur;

void Init() {
    for (int i = 0; i < name.size(); ++i) {
        cmp_str.push_back('A');
    }
    if (name[cur] != 'A') {
        answer += min(name[cur] - 'A', 'Z' - name[cur] + 1);
        name[cur] = 'A';
    }
}


int left_move(int cur) {
    int cnt = 0;

    while (1) {
        cur--;
        cnt++;
        if (cur < 0) cur += name.size();
        if (name[cur] != 'A') return cnt;
    }
}

int right_move(int cur) {
    int cnt = 0;

    for (int i = cur + 1; i < name.size(); ++i) {
        cnt++;
        if (name[i] != 'A') return cnt;
    }
    return INT_MAX;
}

int solution(string n) {
    name = n;

    int cur = 0;
    Init();

    while (cmp_str != name) {

        if (left_move(cur) < right_move(cur)) {
            answer += left_move(cur);
            cur -= left_move(cur);
            if (cur < 0) cur += name.size();
        }
        else {
            answer += right_move(cur);
            cur += right_move(cur);
        }

        answer += min(name[cur] - 'A', 'Z' - name[cur] + 1);
        name[cur] = 'A';
    }

    return answer;
}

void input() {
    cout << solution("JEROEN");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();

    return 0;
}