#include <bits/stdc++.h>
using namespace std;
//int a[4][4]; (1)
vector<string> a;
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/ freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string str; cin >> str;
        a.push_back(str);
    }

    //문제 조건이 붙어서 들어온다. 확인해라.
    //scanf는 이런식으로 해결이 가능하다.

    // scanf("%d %d",&n,&m);
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         scanf("%1d",&a[i][j]);
    //     }
    // }



    int answer = 0;

    // 0 : - , 1 : |
    for (int s = 0; s < (1 << (n * m)); ++s)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            int cur = 0;
            for (int ii = 0; ii < m; ++ii)
            {
                int k = i * m + ii;
                //여기서 s는 0~ 16까지 연속되어지게 이루어짐
                //k는 i는 행의 번호, m은 열의 총 개수.
                if ((s & (1 << k)) == 0)
                {
                    //cur = cur * 10 + a[i][ii]; //(1)  scanf 사용시
                    cur = cur * 10 + (a[i][ii] -'0');
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
                    //cur = cur * 10 + a[i][ii]; //(1)  scanf 사용시
                    cur = cur * 10 + (a[i][ii]-'0');
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