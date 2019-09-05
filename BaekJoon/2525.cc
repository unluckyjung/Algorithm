#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int time1, time2;
    cin >> time1 >> time2;
    int addtime;
    cin >> addtime;

    time2 += addtime;

    int overtime = time2 / 60;
    if (overtime > 0)
    {
        time1 += overtime;
        time2 %= 60;
    }

    if (time1 > 23)
    {
        time1 %= 24;
    }

    cout << time1 << " " << time2;
    return 0;
}