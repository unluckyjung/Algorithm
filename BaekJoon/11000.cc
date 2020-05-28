#include <bits/stdc++.h>
#define pp pair<int,int>
#define start_time first
#define end_time second

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n;
pp _class[200002];

void Solve() {
    for (int i = 0; i < n; ++i) {
        if (!pq.empty()) {
			int fastest_fin = pq.top();
			if (fastest_fin <= _class[i].start_time) pq.pop();
		}
        pq.push(_class[i].end_time);
	}
    cout << (int)pq.size() << "\n";
}

void Input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> _class[i].start_time >> _class[i].end_time;
    }
    sort(_class, _class + n);
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