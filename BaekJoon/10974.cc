#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec;
int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1 ; i<=n; ++i)  vec.push_back(i);

    do{
        for(int it : vec){
            cout << it << " ";
        }
        cout << "\n";
    }while(next_permutation(vec.begin(), vec.end()));

    return 0;
}