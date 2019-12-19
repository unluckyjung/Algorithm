#include <bits/stdc++.h>
using namespace std;

int n;
int answer;

int task[16];
int price[16];

void sol(int day, int money_sum){
    if(day == n){
        answer = max(answer , money_sum);
        return;
    }
    if(day>n) return;
    answer = max(answer , money_sum);

    sol(day + task[day], money_sum + price[day]);
    sol(day + 1, money_sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0 ;i<n; ++i){
        cin >> task[i] >> price[i];
    }

    sol(0, 0);
    cout << answer << "\n";

    return 0;
}