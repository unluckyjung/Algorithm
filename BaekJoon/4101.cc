#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n1, n2;
    while (cin >> n1 >> n2)
    {
        if (n1 == 0 && n2 == 0)
        {
            break;
        }

        if (n1 > n2)
        {
            cout << "Yes"
                 << "\n";
        }
        else
        {
            cout << "No"
                 << "\n";
        }
    }

    return 0;
}