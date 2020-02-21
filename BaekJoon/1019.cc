#include <bits/stdc++.h>
using namespace std;

int page[10];
int s = 1, e;
int digit_num = 1;
int tmp = 1;

void output() {
    for (int i = 0; i <= 9; ++i) {
        cout << page[i] << " ";
    }
}

void one_nine_appear(int n) {
    for (int i = 0; i <= 9; ++i) {
        page[i] += n;
    }
}

void appear_check(int n) {
    while (n) {
        page[n % 10] += digit_num;
        n /= 10;
    }
}

void solve() {
    while (1) {
        while (s % 10 != 0 and s <= e) {
            appear_check(s);
            s++;
        }
        if (s > e)break;

        while (e % 10 != 9 and s <= e) {
            appear_check(e);
            e--;
        }
        s /= 10;
        e /= 10;
        tmp = (e - s + 1);
        one_nine_appear(tmp * digit_num);

        digit_num *= 10;
    }
}

void input() {
    cin >> e;
}
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    solve();
    output();

    return 0;
}