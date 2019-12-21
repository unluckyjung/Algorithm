#include <bits/stdc++.h>
using namespace std;

int a[5][5];
int n, m;
int answer;

void input(){
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        string tmp;
        cin >> tmp;
        for (int ii = 0; ii < tmp.size(); ++ii)
        {
            a[i][ii] = tmp[ii]-'0';
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/ freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for (int s = 0; s < (1 << (n * m)); ++s)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            int cur = 0;
            for (int ii = 0; ii < m; ++ii)
            {
                int k = i * m + ii;
                if ((s & (1 << k)) == 0)
                {
                    cur = cur * 10 + a[i][ii];
                }
                else
                {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        for (int ii = 0; ii < m; ++ii)
        {
            int cur = 0;
            for (int i = 0; i < n; ++i)
            {
                int k = i * m + ii;
                if ((s & (1 << k)) != 0)
                {
                    cur = cur * 10 + a[i][ii];
                }
                else
                {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        answer = max(answer, sum);
    }

    cout << answer << "\n";
    return 0;
}