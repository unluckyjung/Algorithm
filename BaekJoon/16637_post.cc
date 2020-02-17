#include <bits/stdc++.h>
using namespace std;
int len, last_index;
int answer = INT_MIN;
string str;

int calculate(int a, char oper, int b) {
    if (oper == '+')return a + b;
    else if (oper == '-')return a - b;
    else return a * b;
}

void dfs(int cur_value, int cur_index) {
    if (cur_index > last_index) {
        answer = max(answer, cur_value);
        return;
    }
    char oper;
    if (cur_index == 0) oper = '+';
    else oper = str[cur_index - 1];

    if (cur_index + 2 <= last_index) {
        char first_oper = str[cur_index + 1];

        int first_cal = calculate(str[cur_index]-'0', first_oper, str[cur_index + 2]-'0');
        int next_value = calculate(cur_value, oper, first_cal);

        dfs(next_value, cur_index + 4);
    }

    int next_value = calculate(cur_value, oper, str[cur_index] - '0');
    dfs(next_value, cur_index + 2);

}

int solve() {
    last_index = len - 1;
    dfs(0, 0);
    return answer;
}

void input() {
    cin >> len;
    cin >> str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL); cout.tie(NULL);
    input();
    cout << solve();

    return 0;
}