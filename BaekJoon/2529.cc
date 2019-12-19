#include <bits/stdc++.h>
using namespace std;
string cmd;
int arr[10];
bool used[10];
int k;

vector<string> ans;

void solve(int cnt) {
    if (cnt == k + 1) {

        for (int i = 0; i < k; ++i) {
            if (cmd[i] == '<') {
                if (arr[i] < arr[i + 1])   continue;
                else return;
            }
            else {
                if (arr[i] > arr[i + 1])   continue;
                else return;
            }
        }

        string tmp;
        for (int i = 0 ; i<k+1; ++i) {
            tmp.push_back(arr[i] + '0');
        }
        ans.push_back(tmp);
        return;
    }

    for (int i = 0; i <= 9; ++i) {
        if (used[i])continue;
        used[i] = true;
        arr[cnt] = i;
        solve(cnt + 1);
        used[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for (int i = 0; i < k; ++i) {
        char c; cin >> c;
        cmd.push_back(c);
    }
    solve(0);

    sort(ans.begin(), ans.end());
    cout << ans.back() << "\n" << ans.front() << "\n";
    return 0;
}