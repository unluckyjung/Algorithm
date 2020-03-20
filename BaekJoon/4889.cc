#include <bits/stdc++.h>
using namespace std;

string str;

bool end_check() {
    if (str[0] == '-')  return true;
    else return false;
}

int solve() {
    stack<char> s;
    int oper_cnt = 0;

    for (char bracket : str) {
        if (bracket == '{') s.push(bracket);
        else {
            if (s.empty()) {
                s.push('{');
                oper_cnt++;
            }
            else if (s.top() == '{') s.pop();
        }
    }

    oper_cnt += (int)s.size() / 2;
    return oper_cnt;
}

void input() {
    int cnt = 1;
    while (1) {
        cin >> str;
        if (end_check()) return;
        cout << cnt++ << ". " << solve() << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();

    return 0;
}