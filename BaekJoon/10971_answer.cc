#include <bits/stdc++.h>
using namespace std;

int w[20][20];
int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/ freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int ii = 0; ii < n; ++ii)
        {
            cin >> w[i][ii];
        }
    }

    vector<int> d(n);
    for (int i = 0; i < n; ++i)
    {
        d[i] = i;
    }

    int answer = INT_MAX;

    do
    {
        bool ok = true;
        int sum = 0;
        for (int i = 0; i < n-1; ++i)
        {
            int cur = d[i];
            int next = d[i+1];
            if(w[cur][next] == 0)   ok = false;
            else sum += w[cur][next];
            
        }
        int start = d[0];
        int last = d[n-1];
        if(ok && w[last][start] !=0){
            sum += w[last][start];
            answer = min(answer, sum);
        }

    } while (next_permutation(d.begin(), d.end()));

    cout << answer <<"\n";
    return 0;
}