#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, sum = 0;

    for (int i = 0; i < 5; ++i)
    {
        cin >> num;

        if (num < 40)
        {
            num = 40;
        }

        sum += num;
    }

    cout << sum / 5;
    return 0;
}