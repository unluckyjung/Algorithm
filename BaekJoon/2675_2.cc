#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;
    while (count--)
    {
        int repeat;
        cin >> repeat;
        string str;
        cin >> str;
        for (auto i : str)
        {
            for (int j = 0; j < repeat; j++)
            {
                cout << i;
            }
        }
        cout << "\n";

    }

    return 0;
}