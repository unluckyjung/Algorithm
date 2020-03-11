#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> q;


int BACK() {
    if (q.empty())return -1;
    else return q.back();
}

int FRONT() {
    if (q.empty())return -1;
    else return q.front();
}

int POP() {
    int ret;
    if (q.empty())  return -1;
    else {
        ret = q.front();
        q.pop();
    }
    return ret;
}
void solve() {
    string cmd;
    int num;

    cin >> cmd;
    if (cmd == "push") {
        cin >> num;
        q.push(num);
    }
    else if (cmd == "pop") cout << POP() << "\n";
    else if (cmd == "size") cout << q.size() << "\n";
    else if (cmd == "empty") {
        if (q.empty()) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    else if (cmd == "front") cout << FRONT() << "\n";
    else if (cmd == "back") cout << BACK() << "\n";

}

void input() {
    cin >> n;
    while (n--) {
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