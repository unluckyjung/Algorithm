#include <bits/stdc++.h>
using namespace std;

bool _using[102];
vector<int> plug, input_list;
int n, k;
int answer;

void Page_fault(int page, int cur_idx) {
    if (plug.size() < n) {
        plug.push_back(page);
        _using[page] = true;
        return;
    }

    answer++;
    int best_dist = 0;
    int best_idx = 0;
    int best_candidate = plug[best_idx];

    for (int idx = 0; idx < (int)plug.size(); ++idx) {
        int candidate = plug[idx];
        auto exist = find(input_list.begin() + cur_idx, input_list.end(), candidate);

        if (exist == input_list.end()) {
            _using[candidate] = false;
            _using[page] = true;
            plug[idx] = page;
            return;
        }

        int dist = exist - input_list.begin();
        if (best_dist < dist) {
            best_candidate = candidate;
            best_dist = dist;
            best_idx = idx;
        }
    }

    _using[best_candidate] = false;
    _using[page] = true;
    plug[best_idx] = page;
}

void Solve() {
    for (int i = 0; i < k; ++i) {
        int page = input_list[i];

        if (_using[page]) continue;
        Page_fault(page, i);
    }
    cout << answer << "\n";
}

void Input() {
    cin >> n >> k;
    input_list.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> input_list[i];
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