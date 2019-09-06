#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    while (num != 1)
    {
        for (int i = 2; i <= 10000000; ++i)
        {
            if (num % i == 0)
            {
                num /= i;
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}