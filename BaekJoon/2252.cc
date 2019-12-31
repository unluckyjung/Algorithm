#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> vec[32001];
int student[32001];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);

    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    //vector<int> student(n+1, 0);
    
    while(m--){
        int a, b;
        cin >> a >> b;
        student[b]++;
        vec[a].push_back(b);
    }

    for(int i = 1; i<=n; ++i){
        if(student[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        cout << cur <<" ";
        q.pop();

        for(int it : vec[cur]){
            student[it]--;
            if(student[it] == 0) q.push(it);
        }
    }
    return 0;
}