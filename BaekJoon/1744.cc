#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<ll> vec, positive_vec;

int positive_cnt, negative_cnt;
ll answer, cur;

void Positive(ll &num) {
    if (cur < 0) {
        answer += cur;
        cur = 0;
    }
    if (num == 1) {
        answer += num;
        return;
    }
    
    positive_cnt++;
    if (positive_cnt % 2 != 0) cur = num;
    else {
        answer += num * cur;
        cur = 0;
    }
}

void Negative(ll& num) {
    negative_cnt++;
    if (negative_cnt % 2 != 0) cur = num;
    else {
        answer += num * cur;
        cur = 0;
    }
}

void Solve() {
    for (ll &num : vec) {
        if (num < 0) Negative(num);
        else if (num == 0) cur = 0;
        else positive_vec.push_back(num);
    }

    for (auto it = positive_vec.rbegin(); it != positive_vec.rend(); ++it) {
        Positive(*it);
    }

    answer += cur;
    cout << answer << "\n";
}

void Input() {
    cin >> n;
    vec.resize(n);

    for (ll& num : vec) {
        cin >> num;
    }
    sort(vec.begin(), vec.end());
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