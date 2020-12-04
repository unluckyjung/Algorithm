#include <bits/stdc++.h>
using namespace std;

int n, m;
bool isInvited[502];
vector<int> node[502];

int answer = 0;

void inviteFriend(int inviter, int depth) {
    if (depth == 2) return;

    for (int friendNum : node[inviter]) {
        if (!isInvited[friendNum]) {
            isInvited[friendNum] = true;
            answer++;
        }
        inviteFriend(friendNum, depth + 1);
    }
}

void solve() {
    cin >> n;
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        node[s].push_back(e);
        node[e].push_back(s);
    }

    isInvited[1] = true;
    inviteFriend(1, 0);
    cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    solve();

    return 0;
}