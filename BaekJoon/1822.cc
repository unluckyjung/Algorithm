#include <bits/stdc++.h>
using namespace std;

vector<int> A, B;

void Solve() {

    vector<int> result;
    int cnt = 0;
    for (const int& a : A) {
        if (!binary_search(B.begin(), B.end(), a)) {
            result.push_back(a);
        }
    }

    cout << result.size() << "\n";
    for (const int& answer : result) {
        cout << answer << " ";
    }
}

void Input() {
    int n, m;
    cin >> n >> m;
    A.resize(n);
    B.resize(m);

    for (int& it : A) {
        cin >> it;
    }

    for (int& it : B) {
        cin >> it;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
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