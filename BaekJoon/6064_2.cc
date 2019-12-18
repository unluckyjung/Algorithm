#include <bits/stdc++.h>
using namespace std;

int m, n, x, y;
int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--)
    {
        cin >> m >> n >> x >> y;
        x--, y--;
        bool err = true;
        for(int i = x; i< m*n; i+=m){
            if(i%n == y){
                cout << i + 1 <<"\n";
                err = false;
                break;
            }
        }
        if(err) cout << -1 <<"\n";
    }
    return 0;
}