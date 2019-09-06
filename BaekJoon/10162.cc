#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int time;
    int A = 0, B = 0, C = 0;
    cin >> time;
    if (time % 10 != 0)
    {
        cout << -1;
        return 0;
    }
    while (time - 300 >= 0)
    {
        time -= 300;
        A++;
    }
    while (time - 60 >= 0)
    {
        time -= 60;
        B++;
    }
    while (time - 10 >= 0)
    {
        time -= 10;
        C++;
    }

    cout << A << " " << B << " " << C;

    return 0;
}