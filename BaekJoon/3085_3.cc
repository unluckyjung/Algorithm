#include <bits/stdc++.h>
using namespace std;
char board[51][51];
int n;
int answer;

void input()
{
    for (int i = 0; i < n; ++i)
    {
        for (int ii = 0; ii < n; ++ii)
        {
            cin >> board[i][ii];
        }
    }
}

void find_len()
{
    for (int i = 0; i < n; ++i)
    {
        int cnt = 1;
        for (int ii = 0; ii < n - 1; ++ii)
        {
            if (board[i][ii] == board[i][ii + 1])
                cnt++;
            else
                cnt = 1;
            answer = max(answer, cnt);
        }

        cnt = 1;
        for (int ii = 0; ii < n - 1; ++ii)
        {
            if (board[ii][i] == board[ii + 1][i])
                cnt++;
            else
                cnt = 1;
            answer = max(answer, cnt);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    input();

    for (int i = 0; i < n; ++i)
    {
        for (int ii = 0; ii < n; ++ii)
        {
            if (ii + 1 < n)
            {
                if (board[i][ii] != board[i][ii + 1])
                {
                    swap(board[i][ii], board[i][ii + 1]);
                    find_len();
                    swap(board[i][ii], board[i][ii + 1]);
                }
            }

            if (i + 1 < n)
            {
                if (board[i][ii] != board[i + 1][ii])
                {
                    swap(board[i][ii], board[i + 1][ii]);
                    find_len();
                    swap(board[i][ii], board[i + 1][ii]);
                }
            }
        }
    }
    cout << answer << "\n";
    return 0;
}