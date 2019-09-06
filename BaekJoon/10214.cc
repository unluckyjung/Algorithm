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
        pair<int, int> score;
        score = make_pair(0, 0);
        
        for (int i = 0; i < 9; i++)
        {
            int n1, n2;
            cin >> n1 >> n2;
            score.first += n1;
            score.second += n2;
        }
        if (score.first > score.second)
        {
            cout << "Yonsei"
                 << "\n";
        }
        else if (score.first < score.second)
        {
            cout << "Korea"
                 << "\n";
        }
        else if (score.first == score.second)
        {
            cout << "Draw"
                 << "\n";
        }
    }

    return 0;
}