#include <bits/stdc++.h>
using namespace std;

int board[501][501];
int n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    for(int i = 0 ; i<n ;++i){
        for(int ii = 0 ; ii<m; ++ii){
            cin >> board[i][ii];
        }
    }

    
    return 0;
}