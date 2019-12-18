#include <bits/stdc++.h>
using namespace std;

int m, n;
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
        bool check = true;
        cin >> m >> n >> x >> y;
        x--, y--;
        for (int k = x; k < m * n; k += m)
        {
            if (k % n == y)
            {
                cout << k + 1 << "\n";
                check = false;
                break;
            }
        }
        if (check)  cout << -1 << "\n";
    }
    return 0;
}