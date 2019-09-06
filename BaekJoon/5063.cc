#include <bits/stdc++.h>
using namespace std;
void adv(int &n1, int &n2, int &n3)
{
    if (n2 - n3 < n1)
    {
        cout << "do not advertise"
             << "\n";
    }
    else if ((n2 - n3) == n1)
    {
        cout << "does not matter"
             << "\n";
    }
    else if ((n2 - n3) > n1)
    {
        cout << "advertise"
             << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;
    while (count--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        adv(n1, n2, n3);
    }

    return 0;
}