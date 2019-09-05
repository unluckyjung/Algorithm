#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int hour, min, sec;

    cin >> hour >> min >> sec;

    int add_time;
    cin >> add_time;

    sec += add_time;

    if (sec >= 60)
    {
        min += sec / 60;
        sec %= 60;
    }

    if (min >= 60)
    {
        hour += min / 60;
        min %= 60;
    }

    if (hour >= 24)
    {
        hour %= 24;
    }

    cout << hour << " " << min << " " << sec;

    return 0;
}