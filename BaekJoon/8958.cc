#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    string OX;
    cin >> count;
    while (count--)
    {
        int sum = 0;
        cin >> OX;
        int len = OX.size();

        int temp = 0;
        int combo = 1;
        for (int i = 0; i < len; i++)
        {
            if (OX[i] == 'O')
            {
                temp += combo;
                combo++;
            }
            else
            {
                sum += temp;
                temp = 0;
                combo = 1;
            }

            if (i == len - 1)
            {
                sum += temp;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}