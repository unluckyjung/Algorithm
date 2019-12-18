#include <bits/stdc++.h>
using namespace std;
int n, m;

int arr[10];

void sol(const int &start, const int &cnt){
    if(cnt == m){
        for(int i = 0; i<m; ++i){
            cout << arr[i] << " ";
        }
        cout <<"\n";
        return;
    }
    if(start > n) return;

    arr[cnt] = start;
    sol(start + 1, cnt + 1);
    sol(start + 1, cnt);

}
int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    sol(1,0);
    return 0;
}