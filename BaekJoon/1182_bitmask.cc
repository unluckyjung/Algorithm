#include <bits/stdc++.h>
using namespace std;

int a[20];
int n, s;
int answer;
int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >>s;

    for(int i = 0 ; i<n; ++i){
        cin >> a[i];
    }

    for (int i = 1; i < (1 << n); ++i)
    {
        int sum = 0;
        for (int k = 0; k < n; ++k)
        {
            if (i & (1 << k))
            {
                sum += a[k];
            }
        }
        if (sum == s)
        {
            answer++;
        }
    }
    cout << answer << "\n";
    return 0;
}