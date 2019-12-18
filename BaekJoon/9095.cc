#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int answer;

void solve(int sum){
    if(sum == n){
        answer++;
        return;
    }

    if(sum < n){
        for(int i = 1; i<=3; ++i){
            solve(sum + i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        answer = 0;
        cin >> n;
        solve(0);
        cout << answer <<"\n";
    }

    return 0;
}