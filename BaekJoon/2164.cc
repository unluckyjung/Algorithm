#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> card_box;

void solve() {
    int cur;

    while(card_box.size() != 1) {
        card_box.pop();
        cur = card_box.front(); card_box.pop();
        card_box.push(cur);
    }
    cout << card_box.front() << "\n";
}

void input() {
    cin >> n;
    for (int card = 1; card <= n; ++card) 
        card_box.push(card);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}