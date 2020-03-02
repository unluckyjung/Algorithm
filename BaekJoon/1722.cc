#if 01

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> vec;
int n;

int get_idx(int k) {
    for (int i = 0; i <= (int)vec.size(); ++i) {
        if (k != vec[i])continue;
        vec.erase(vec.begin() + i);
        return i;
    }
    return -1;
}

ll get_fac(int num) {
    ll ret = 1;
    for (ll i = 1; i <= num; ++i) 
        ret *= i;

    return ret;
}

void solve_q2() {
    int k, fac_n = n - 1;
    int idx;
    ll sum = 0;
    for (int i = fac_n; i >= 0; --i) {
        cin >> k;
        idx = get_idx(k);
        sum += idx * get_fac(i);
    }
    cout << sum + 1;
}

void solve_q1() {
    ll k;
    int fac_n = n - 1;
    cin >> k;
    k--;

    for (int i = fac_n; i >= 0; --i) {
        int idx = k / get_fac(i);
        k %= get_fac(i);
        cout << vec[idx] << " ";
        vec.erase(vec.begin() + idx);
    }
}

void input() {
    int quiz;
    cin >> n >> quiz;

    for (int i = 1; i <= n; ++i)   vec.push_back(i);

    if (quiz == 1) solve_q1();
    else solve_q2();
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();

    return 0;
}


#else

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
vector<int> vec;

ll fac(int k) {
    ll fac_result = 1;

    for (int i = 1; i <= k; ++i) {
        fac_result *= i;
    }

    return fac_result;
}

int find_index(int value) {
    for (int index = 0; index < (int)vec.size(); ++index) {
        if (vec[index] == value) {
            vec.erase(vec.begin() + index);
            return index;
        }
    }
    return -1;
}

void solve_q2(const vector<int> &want_vec) {
    ll answer = 1;
    int fac_start = n - 1;
    int index;
    ll fac_result;
    for (int i = 0; i < n; ++i) {
        fac_result = fac(fac_start); 
        fac_start--;
        index = find_index(want_vec[i]);
        answer += index * fac_result;
    }
    cout << answer << "\n";
}


void solve_q1(ll cnt) {
    int fac_start = n - 1;
    int index;
    ll fac_result;
    for (int i = fac_start; i >= 0; --i) {
        fac_result = fac(i);

        index = cnt / fac_result;
        cnt %= fac_result;

        cout << vec[index] << " ";
        vec.erase(vec.begin() + index);
    }
}

void solve(int q) {
    if (q == 1) {
        ll cnt;    cin >> cnt;
        solve_q1(cnt - 1);
    }
    else if (q == 2) {
        vector<int> want_vec;
        int num;
        for (int i = 1; i <= n; ++i) {
            cin >> num;
            want_vec.push_back(num);
        }
        solve_q2(want_vec);
    }
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        vec.push_back(i);
    }
    int quiz;   cin >> quiz;
    solve(quiz);
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    return 0;
}

#endif