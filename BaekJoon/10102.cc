#include <bits/stdc++.h>
using namespace std;

void winner(const string &vote, const int &count)
{
    int Acount = 0;
    int Bcount = 0;
    for (int i = 0; i < count; ++i)
    {
        if (vote[i] == 'A')
        {
            Acount++;
        }
        else if (vote[i] == 'B')
        {
            Bcount++;
        }
    }
    if (Acount > Bcount)
    {
        cout << 'A';
    }
    else if (Bcount > Acount)
    {
        cout << 'B';
    }
    else if (Bcount == Acount)
    {
        cout << "Tie";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    string vote;
    cin >> vote;
    winner(vote, count);

    return 0;
}