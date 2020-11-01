#include <bits/stdc++.h>
#define pii pair<char,int>
#define bracket first
#define insideValue second

using namespace std;

string str;

int solve() {
    cin >> str;
    stack<pii> s;

    int answer = 0;
    for (const char &c : str) {
        int tmp = 0;

        if (c == ')') {
            if (s.empty() or s.top().bracket != '(') return 0;

            if (s.top().insideValue == 0) tmp = 2;  // 괄호안에 다른 괄호가 없는 경우.
            else tmp = s.top().insideValue * 2;
            
            s.pop();
            if (s.empty()) answer += tmp;   // 괄호를 감싸는 다른 괄호가 없는 경우
            else s.top().insideValue += tmp;
        }
        else if (c == ']') {
            if (s.empty() or s.top().bracket != '[') return 0;

            if (s.top().insideValue == 0) tmp = 3;
            else tmp = s.top().insideValue * 3;

            s.pop();
            if (s.empty()) answer += tmp;
            else s.top().insideValue += tmp;
        }
        else s.push({ c, 0 });
    }
    return answer;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    cout << solve();

    return 0;
}