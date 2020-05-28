#include <bits/stdc++.h>
using namespace std;

int n, tape_len, tape_cnt;
double cur;

int weak[1002];

void Solve() {
    for (int i = 0; i < n; ++i) {
		if (cur < double(weak[i] - 0.5)) {
			cur = weak[i] - 0.5 + tape_len;
			tape_cnt++;
		}
		if (cur < double(weak[i] + 0.5)) {
			cur = weak[i] + 0.5 + tape_len;
			tape_cnt++;
		}
    }
    cout << tape_cnt;
}

void Input() {
    cin >> n >> tape_len;
    for (int i = 0; i < n; ++i) {
        cin >> weak[i];
    }
    sort(weak, weak + n);
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