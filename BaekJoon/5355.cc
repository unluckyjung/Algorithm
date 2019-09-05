#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(2);

    int count;
    cin >> count;
    while (count--)
    {
        double num1;
        string arr;

        cin >> num1;
        getline(cin, arr);

        for (auto i : arr)
        {
            if (i == '@')
            {
                num1 *= 3.0;
            }
            else if (i == '%')
            {
                num1 += 5.0;
            }
            else if (i == '#')
            {
                num1 -= 7.0;
            }
        }

        cout << num1 << "\n";
    }

    return 0;
}