#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    int result = 0;
    cin >> count;
    while (count--)
    {
        int vote;
        cin >> vote;
        if (vote == 1)
        {
            result++;
        }
        else if (vote == 0)
        {
            result--;
        }
    }
    if (result > 0)
    {
        cout << "Junhee is cute!";
    }
    else
    {
        cout << "Junhee is not cute!";
    }

    return 0;
}