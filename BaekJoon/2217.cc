#include <bits/stdc++.h>
using namespace std;

int rope[100002];
int n;

void Solve() {
    int answer = 0;
	for (int i = 1; i <= n; ++i) {
		answer = max(answer, rope[i - 1] * i);
	}
	cout << answer << "\n";
}

void Input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> rope[i];
    }
    sort(rope, rope + n, greater<int>());
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