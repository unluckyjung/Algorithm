#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2;
    while (cin >> n1 >> n2)
    {
        if (n1 == 0 && n2 == 0)
        {
            return 0;
        }
        else if (n1 % n2 == 0)
        {
            cout << "multiple"
                 << "\n";
        }
        else if (n2 % n1 == 0)
        {
            cout << "factor"
                 << "\n";
        }
        else{
            cout << "neither"
                 << "\n";        }
    }

    return 0;
}