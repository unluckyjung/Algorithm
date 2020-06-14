#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> nums;

unordered_map<string, bool> m;

void Solve() {
    int answer = 0;

    sort(nums.begin(), nums.end());
    do {
        string num = "";
        for (int i = 0; i < k; ++i) {
            num += to_string(nums[i]);
        }
        if (m[num]) continue;
        m[num] = true;
        answer++;
    } while (next_permutation(nums.begin(), nums.end()));

    cout << answer << "\n";
}

void Input() {
    cin >> n;
    cin >> k;

    nums.resize(n);
    for (auto& it : nums) {
        cin >> it;
    }
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