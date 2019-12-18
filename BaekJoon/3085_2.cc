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

int get_length()
{
    int max_len = 0;

    for (int i = 0; i < n; ++i)
    {
        int cnt = 1;
        for (int ii = 0; ii + 1 < n; ++ii)
        {
            if (board[i][ii] == board[i][ii + 1])
                cnt++;
            else
                cnt = 1;

            max_len = max(max_len, cnt);
        }

        cnt = 1;
        for (int ii = 0; ii + 1 < n; ++ii)
        {
            if (board[ii][i] == board[ii+1][i])
                cnt++;
            else
                cnt = 1;

            max_len = max(max_len, cnt);
        }
    }
    return max_len;
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
            if (ii + 1 < n && board[i][ii+1] != board[i][ii])
            {
                swap(board[i][ii], board[i][ii + 1]);
                int tmp = get_length();
                answer = max(answer, tmp);
                swap(board[i][ii], board[i][ii + 1]);
            }

            if(i + 1 <n && board[i][ii] != board[i+1][ii]){
                swap(board[i][ii], board[i+1][ii]);
                int tmp = get_length();
                answer = max(answer, tmp);
                swap(board[i][ii], board[i+1][ii]);
            }
        }
    }

    cout << answer <<"\n";

    return 0;
}