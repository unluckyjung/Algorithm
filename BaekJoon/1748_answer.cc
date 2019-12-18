#include <bits/stdc++.h>
using namespace std;

int n;
long long answer;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int len = 0;
    for(int start = 1; start<=n; start *= 10){
        len ++;
        int end = start * 10 -1;
        if(n < end) end = n;
        
        answer += len * (end - start + 1);
    }

    cout << answer <<"\n";
    return 0;
}