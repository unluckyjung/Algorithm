#include <bits/stdc++.h>
using namespace std;

int day[1300];
int flower[1300];
int n;

int Solve() {

    int n_flower_death = 0, b_flower_death = 301;
    int flower_cnt = 0;
    int day = 101;

    while (day < 1300) {
        while (day <= b_flower_death) {
            n_flower_death = max(n_flower_death, flower[day]);
            if (n_flower_death > 1130) return flower_cnt + 1;
            day++;
        }
        if (n_flower_death <= b_flower_death) return 0;
        
        flower_cnt++;
        b_flower_death = n_flower_death;
    }


    return 0;
}

void Input() {
    cin >> n;

    int s_m, s_d, e_m, e_d;
    for (int i = 0; i < n; ++i) {
        cin >> s_m >> s_d >> e_m >> e_d;

        int s_day = s_m * 100 + s_d;
        int e_day = e_m * 100 + e_d;
        flower[s_day] = max(flower[s_day], e_day);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    Input();
    cout << Solve();

    return 0;
}