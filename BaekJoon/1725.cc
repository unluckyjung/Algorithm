//stl 안쓰고 풀어보기
#include<iostream>
#define ll long long
using namespace std;

int sp;
ll answer;

struct stack {
    ll idx;
    ll h;
};

stack st[100001];

int size() { return sp; }
void push(stack data) { st[++sp] = data; }
void pop() { sp--; }
bool empty() { return sp == 0; }
stack top() { return st[sp]; }

int n;

void empty_check() {
    while (!empty()) {
        ll area = top().h * (n - top().idx);
        if (area > answer) answer = area;
        pop();
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        stack cur;

        cur.idx = i;
        cin >> cur.h;

        while (!empty() && top().h >= cur.h) {
            ll area = top().h * (i - top().idx);
            if (area > answer) answer = area;
            cur.idx = top().idx;
            pop();
        }
        push(cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    input();
    empty_check();

    cout << answer;

    return 0;
}