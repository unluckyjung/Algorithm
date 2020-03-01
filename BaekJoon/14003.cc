#include <bits/stdc++.h>
#define pp pair<int, int>
#define index first
#define value second
using namespace std;

vector<int> vec{ INT_MIN };
vector<pp> path;
stack<int> answer;
int n;

void print_path() {
    int len = vec.size() - 1;

   for (int i = path.size() - 1; i >= 0; --i) {
       if (path[i].index != len)continue;
       len--;
       answer.push(path[i].value);
   }

   while (!answer.empty()) {
       cout << answer.top() <<" ";
       answer.pop();
   }
}

void make_sequence(int num){
    int idx;
    if (num > vec.back()) {
        idx = vec.size();
        vec.push_back(num);
    }
    else {
        auto it = lower_bound(vec.begin(), vec.end(), num);
        idx = it - vec.begin();
        *it = num;
    }
    path.push_back({ idx, num });
}

void solve() {
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        make_sequence(num);
    }
    cout << vec.size() - 1 << "\n";
    print_path();
}

void input() {
    cin >> n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    solve();

    return 0;
}