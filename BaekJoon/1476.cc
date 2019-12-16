#include <bits/stdc++.h>

using namespace std;

int year;

int E, S, M;
int e, s, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> E >> S >> M;

    while (1)
    {
        year++;
        e = e % 15 + 1;
        s = s % 28 + 1;
        m = m % 19 + 1;
        if (e == E && s == S && m == M)
        {
            cout << year;
            return 0;
        }
    }
    return 0;
}