#include <bits/stdc++.h>
using namespace std;
int n, s;
int arr[21];
int answer;

int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s;
    for(int i = 0; i<n; ++i)    cin >> arr[i];

    for(int i = 1; i < (1 << n); ++i){
        int sum = 0;
        for(int index = 0; index < n; ++index){
            if(i&(1 << index)) sum+=arr[index];
        }
        if(sum == s)answer ++;
    }
    cout << answer <<"\n";
    return 0;
}