#include <bits/stdc++.h>
using namespace std;

bool used[50];
vector<int> lotto;
int n;

void get_number(int start, int cnt)
{
    //cout << "123";
    if (cnt == 6)
    {
        for (int it : lotto)
        {
            if(!used[it])continue;
            cout << it << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < n; ++i)
    {
        if (used[lotto[i]])
            continue;

        used[lotto[i]] = true;
        get_number(i + 1, cnt + 1);
        used[lotto[i]] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/ freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        cin >> n;
        if (n == 0)
            break;

        lotto.clear();
        memset(used, false, sizeof(used));

        for (int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            lotto.push_back(num);
        }
        get_number(0, 0);
        cout <<"\n";

    }
    return 0;
}