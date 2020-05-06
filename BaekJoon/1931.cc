#include <bits/stdc++.h>
#define pp pair<int, int>
#define end first
#define start second
using namespace std;

pp meeting[100002];
int n;

bool comp(const pp &a, const pp &b) {
    if (a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}


void Solve() {
    int cur = 0, cnt = 0;
    
    for (int i = 0; i < n; ++i) {
        if (meeting[i].start < cur) continue;
        cur = meeting[i].end;
        cnt++;
    }
    cout << cnt << "\n";
}

void Input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> meeting[i].start >> meeting[i].end;
    }

    sort(meeting, meeting + n);
    //sort(meeting, meeting + n, comp);
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