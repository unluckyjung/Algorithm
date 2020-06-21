#include <bits/stdc++.h>
using namespace std;

string st, answer;
stack<char> s;

void Oper_Func(const char &oper) {
    if (oper == '*' or oper == '/') {
        while (!s.empty() and (s.top() == '*' or s.top() == '/')) {
            answer += s.top();
            s.pop();
        }
        s.push(oper);
    }

    else if (oper == '+' or oper == '-') {
        while (!s.empty() and s.top() != '(') {
            answer += s.top();
            s.pop();
        }
        s.push(oper);
    }
}

void Bracket_Func(const char& bracket) {
    if (bracket == '(') s.push('(');
    else {
        while (!s.empty()) {
            char cur = s.top(); s.pop();
            if (cur == '(') break;
            answer += cur;
        }
    }
}

void Solve() {
    for (const char &ch : st) {
        if (isalpha(ch)) answer += ch;
        else {
            if (ch == '(' or ch == ')') Bracket_Func(ch);
            else Oper_Func(ch);
        }
    }

    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }

    cout << answer << "\n";
}

void Input() {
    cin >> st;
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