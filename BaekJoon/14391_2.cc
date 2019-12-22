#include <bits/stdc++.h>
using namespace std;
int n, m;
int answer;
int board[5][5];

void input(){
    cin >> n >> m;
    for(int i = 0; i<n; ++i){
        string line;
        cin >> line;
        for(int ii =0; ii<m; ++ii){
            board[i][ii] = line[ii]-'0';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    input();


    for(int s = 0; s < (1<<(n*m)); ++s){
        int sum = 0;
        for(int i = 0 ; i<n; ++i){
            int cur = 0;
            for(int ii = 0; ii<m; ++ii){
                int k = i * m +ii;
                if(((1<<k) & s) == 0){
                    cur = cur*10 + board[i][ii];
                }
                else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }


        for(int ii = 0; ii <m; ++ii){
            int cur = 0;
            for(int i = 0 ;i <n; ++i){
                int k = i*m + ii;
                if(((1<<k)&s)!=0){
                    cur = cur*10 + board[i][ii];
                }
                else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum +=cur;
        }
        answer = max(answer ,sum);
    }

    cout << answer <<"\n";
    return 0;
}