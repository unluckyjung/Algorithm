#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(1);
    
    string grade;
    cin >> grade;

    if ((grade == "A+") != 0)
        cout << 4.3;
    else if ((grade == "A0") != 0)
        cout << 4.0;
    else if ((grade == "A-") != 0)
        cout << 3.7;
    else if ((grade == "B+") != 0)
        cout << 3.3;
    else if ((grade == "B0") != 0)
        cout << 3.0;
    else if ((grade == "B-") != 0)
        cout << 2.7;
    else if ((grade == "C+") != 0)
        cout << 2.3;
    else if ((grade == "C0") != 0)
        cout << 2.0;
    else if ((grade == "C-") != 0)
        cout << 1.7;
    else if ((grade == "D+") != 0)
        cout << 1.3;
    else if ((grade == "D0") != 0)
        cout << 1.0;
    else if ((grade == "D-") != 0)
        cout << 0.7;
    else
    {
        cout << 0.0;
    }

    return 0;
}