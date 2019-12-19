#include <bits/stdc++.h>
using namespace std;
int n;
int s[21][21];
bool A[21];

int answer = INT_MAX;

void make_team(int k, int cnt){
    if(cnt > n or k >= n) return;

    if(cnt >= 1){
        int A_power = 0, B_power = 0;
        for(int i = 0 ; i<n-1; ++i){
            if (A[i])
            {
                for (int ii = i+1; ii < n; ++ii)
                {
                    if(A[ii]){
                        A_power += s[i][ii];
                        A_power += s[ii][i];
                    }
                }
            }

            else{
                for (int ii = i+1; ii < n; ++ii)
                {
                    if(!A[ii]){
                        B_power += s[i][ii];
                        B_power += s[ii][i];
                    }
                }
            }
        }

        int tmp = abs(A_power - B_power);
        answer = min(answer ,tmp);
    }


    A[k]= true;
    make_team(k+1, cnt+1);
    A[k] = false;
    make_team(k+1, cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0 ; i<n; ++i){
        for(int ii = 0 ;ii<n; ++ii){
            cin >> s[i][ii];
        }
    }

    make_team(0,0);
    cout <<answer << "\n";

    return 0;
}