#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    int Q1 = 0, Q2 = 0, Q3 = 0, Q4 = 0, AXIS = 0;
    cin >> count;
    while (count--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        if (n1 == 0 || n2 == 0)
        {
            AXIS++;
        }
        else if (n1 > 0 && n2 > 0)
        {
            Q1++;
        }
        else if (n1 > 0 && n2 < 0)
        {
            Q4++;
        }
        else if (n1 < 0 && n2 > 0)
        {
            Q2++;
        }
        else if (n1 < 0 && n2 < 0)
        {
            Q3++;
        }
    }

    cout << "Q1: " << Q1 << "\n";
    cout << "Q2: " << Q2 << "\n";
    cout << "Q3: " << Q3 << "\n";
    cout << "Q4: " << Q4 << "\n";
    cout << "AXIS: " << AXIS << "\n";

    return 0;
}