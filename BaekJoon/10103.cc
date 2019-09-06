#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    int A = 100, B = 100;
    cin >> count;

    while (count--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        if (n1 < n2)
        {
            A -= n2;
        }
        else if (n1 > n2)
        {
            B -= n1;
        }
    }
    cout << A << "\n";
    cout << B << "\n";

    return 0;
}