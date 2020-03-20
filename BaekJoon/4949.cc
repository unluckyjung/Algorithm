#include <bits/stdc++.h>
using namespace std;

string str;

bool end_check() {
    if (str == ".") return true;
    else return false;
}

bool braket_check(stack<char> &s, const char &bracket) {
    if (s.empty()) return false;

    if (bracket == ')') {
        if (s.top() != '(') return false;
    }
    else {
        if (s.top() != '[') return false;
    }
   
    s.pop();
    return true;
}

void solve() {
    stack<char> s;

    int str_len = str.size();

    for (int i = 0; i < str_len; ++i) {
        if (str[i] == '(' or str[i] == '[') s.push(str[i]);
        else if (str[i] == ')' or str[i] == ']') {
            if (!braket_check(s, str[i])) {
                cout << "no\n";
                return;
            }
        }
    }

    if (s.empty())   cout << "yes\n";
    else cout << "no\n";
}

void input() {
    while (1) {
        getline(cin, str);
        if (end_check()) return;
        solve();
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