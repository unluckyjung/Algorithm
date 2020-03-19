#if 01

#include <bits/stdc++.h>
#define pp pair<int,int>

using namespace std;

int n, m;
int house_cnt, store_cnt;
int answer = INT_MAX;

struct Store {
    int x, y;
    bool run;
};

vector<pp> house;
vector<Store> store;

int calculate(const pp& h, const Store& s) {
    return abs(h.first - s.x) + abs(h.second - s.y);
}

int get_chicken_distance() {
    int total_distance = 0;
    for (int i = 0; i < house_cnt; ++i) {
        int distance = 123123;
        for (int ii = 0; ii < store_cnt; ++ii) {
            if (store[ii].run == false) continue;
            distance = min(distance, calculate(house[i], store[ii]));
        }
        total_distance += distance;
    }
    return total_distance;
}


void dfs(int store_n, int run_cnt) {
    if (store_cnt - store_n + run_cnt + 1 < m) return;
    if (run_cnt == m) {
        answer = min(answer, get_chicken_distance());
        return;
    }

#if 0
    for (int i = store_n; i < store_cnt; ++i) {
        store[i].run = true;
        dfs(i + 1, run_cnt + 1);
        store[i].run = false;
    }

#else
    store[store_n].run = true;
    dfs(store_n + 1, run_cnt + 1);
    store[store_n].run = false;
    dfs(store_n + 1, run_cnt);

#endif
}

void solve() {
    dfs(0, 0);
    cout << answer << "\n";
}

void input() {
    cin >> n >> m;
    int spot;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> spot;
            if (spot == 1)   house.push_back({ i,ii });
            else if (spot == 2) store.push_back({ i,ii, false });
        }
    }

    house_cnt = house.size();
    store_cnt = store.size();
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

#else

#include <bits/stdc++.h>
#define pp pair<int,int>

using namespace std;

int n, m;
int house_cnt, store_cnt;
int answer = INT_MAX;

vector<pp> house;
vector<pp> store, run_store;

int calculate(const pp &h, const pp &s) {
    return abs(h.first - s.first) + abs(h.second - s.second);
}

int get_chicken_distance() {
    int total_distance = 0;
    for (int i = 0; i < house_cnt; ++i) {
        int distance = 123123;
        for (int ii = 0; ii < m; ++ii) {
            distance = min(distance, calculate(house[i], run_store[ii]));
        }
        total_distance += distance;
    }
    return total_distance;
}


void dfs(int store_n, int run_cnt) {
    if (store_cnt - store_n + run_cnt + 1 < m) return;
    if (run_cnt == m) {
        answer = min(answer, get_chicken_distance());
        return;
    }

    for (int i = store_n; i < store_cnt; ++i) {
        run_store.push_back(store[i]);
        dfs(i + 1, run_cnt + 1);
        run_store.pop_back();
    }
}


void solve() {
    dfs(0, 0);
    cout << answer << "\n";
}

void input() {
    cin >> n >> m;
    int spot;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> spot;
            if (spot == 1)   house.push_back({ i,ii });
            else if (spot == 2) store.push_back({ i,ii });
        }
    }

    house_cnt = house.size();
    store_cnt = store.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}

#endif