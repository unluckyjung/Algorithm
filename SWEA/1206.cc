#include<bits/stdc++.h>

using namespace std;

int building[1001];

int check(int k){
    int start = k-2;
    int end = k+2;

    int MAX = 0;
    for(int i = start; i<= end; ++i){
        if(i == k)continue;
        MAX = max(MAX, building[i]);
    }
    if(MAX < building[k])  return building[k] - MAX;
    else return 0;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    for(int cnt = 1; cnt<=10; ++cnt){
        int n;  cin >> n;
        memset(building, 0, sizeof(building));

        for(int i = 0 ; i<n; ++i){
            cin >> building[i];
        }

        int sum = 0;
        for(int i = 2 ; i<n-2; ++i){
            sum += check(i);
        }
        cout << "#" <<cnt << " " << sum <<"\n";
    }
    return 0;
}