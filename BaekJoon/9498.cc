#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    switch (n / 10)
    {
    case 10:
    case 9:
        cout << 'A';
        break;
    case 8:
        cout << 'B';
        break;
    case 7:
        cout << 'C';
        break;
    case 6:
        cout << 'D';
        break;
    default:
        cout << 'F';
        break;
    }

    return 0;
}