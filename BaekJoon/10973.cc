#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<int> vec;
    while(n--){
        int num;    cin >> num;
        vec.push_back(num);
    }

    if(prev_permutation(vec.begin(), vec.end())){
        for(int it : vec)   cout << it << " ";
    }
    else
    {
        cout << -1 <<"\n";
    }
    
    return 0;
}