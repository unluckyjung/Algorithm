#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y;

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
        int year = 0;
        int nx = 0, ny = 0;
        while (1)
        {
            nx = nx % m + 1;
            ny = ny % n + 1;
            year++;
            if(nx == x && ny == y){
                cout << year <<"\n";
                break;
            }
            else if(nx == m && ny == n){
                cout << -1 <<"\n";
                break;
            }
        }
    }
    return 0;
}