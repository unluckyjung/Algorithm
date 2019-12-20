#include <bits/stdc++.h>
using namespace std;

int n;
int s[10][10];
int ans[10];
string str;

bool check(int index){
    int sum = 0;
    for(int i = index ; i>=0; --i){
        sum+=ans[i];
        if(s[i][index] == 0){
            if(sum != 0)return false;
        }
        if(s[i][index] < 0){
            if(sum >= 0) return false;
        }
        if(s[i][index] > 0){
            if(sum <= 0) return false;
        }
    }
    return true;
}

bool solve(int index){
    if(index == n)  return true;

    if(s[index][index] == 0){
        ans[index] = 0;
        return check(index) and solve(index+1);
    }

    for(int i = 1; i<=10; ++i){
        ans[index] = s[index][index]*i;
        if (check(index) && solve(index+1)) return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> str;

    int cnt = 0;

    for(int i = 0; i<n; ++i){
        for(int ii = i ; ii<n; ++ii){
            if(str[cnt] == '0')   s[i][ii] = 0;
            else if(str[cnt] == '+')    s[i][ii] = 1;
            else if(str[cnt] == '-')    s[i][ii] = -1;
            cnt++;
        }
    }
    solve(0);
    for(int i = 0 ; i<n; ++i){
        cout << ans[i] << " ";
    }
    cout <<"\n";
    return 0;
}