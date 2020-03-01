#include <bits/stdc++.h>
using namespace std;

vector<int> vec = { INT_MAX };
int n;

//num보다 크지 않은, 첫번째 수
void LDS(int s, int e, int num) {
    int mid, idx = 0;

    while (s <= e) {
        mid = (s + e) / 2;

        if (vec[mid] <= num) {
            idx = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }
    if (idx == 0) {
        cout << "err\n";
        return;
    }
    vec[idx] = num;
}

void make_sequence(int num) {
    if (num < vec.back()) {
        vec.push_back(num);
    }
    else {
        //LDS(1, vec.size() - 1, num);

        auto it = lower_bound(vec.begin(), vec.end(), num, greater<int>());
        //num 보다 크지 않은, 첫번째 수
        *it = num;
    }
}

void solve() {
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        make_sequence(num);
    }
    cout << vec.size() - 1 << " ";
}

void input() {
    cin >> n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    solve();

    return 0;
}