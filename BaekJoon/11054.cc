#include <bits/stdc++.h>
using namespace std;

int n, answer;
int LIS_size[1001];
int LDS_size[1001];
int arr[1001];
vector<int> LIS = { INT_MIN };
vector<int> LDS = { INT_MIN };


void make_LIS(int index, int num) {
    if (LIS.back() < num) LIS.push_back(num);
    else {
        auto it = lower_bound(LIS.begin(), LIS.end(), num);
        *it = num;
    }
    LIS_size[index] = (int)LIS.size()-1;
}

void make_LDS(int index, int num) {
    if (LDS.back() < num) LDS.push_back(num);
    else {
        auto it = lower_bound(LDS.begin(), LDS.end(), num);
        *it = num;
    }
    LDS_size[index] = (int)LDS.size() - 1;
}

void Bitonic_check() {

    for (int index = 0; index < n; ++index) {
        int tmp = (LIS_size[index] + LDS_size[index]) - 1;
        answer = max(answer, tmp);
    }
}

void solve() {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        make_LIS(i, arr[i]);
    }

    for (int i = n - 1; i >= 0; --i) {
        make_LDS(i, arr[i]);
    }

    Bitonic_check();

    cout << answer << "\n";
}

void input() {
    cin >> n;
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