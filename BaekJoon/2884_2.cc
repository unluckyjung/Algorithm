#include <bits/stdc++.h>
using namespace std;

void clock(int &hour, int &min)
{
    min -= 45;
    if (min < 0)
    {
        min += 60;
        hour--;
        if (hour < 0)
        {
            hour = 23;
        }
    }
    cout << hour << " " << min;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num1, num2;
    cin >> num1 >> num2;
    clock(num1, num2);

    return 0;
}