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
        cur--; cnt++;
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
        int left_cnt = left_move(cur);
        int right_cnt  = right_move(cur);
        
        if (left_cnt < right_cnt) {
            answer += left_cnt;
            cur -= left_cnt;
            if (cur < 0) cur += name.size();
        }
        else {
            answer += right_cnt;
            cur += right_cnt;
        }

        answer += min(name[cur] - 'A', 'Z' - name[cur] + 1);
        name[cur] = 'A';
    }

    return answer;
}