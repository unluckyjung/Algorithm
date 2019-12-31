#include <bits/stdc++.h>
using namespace std;

int n, m;
int student[32001];
vector<int> node[32001];

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);

    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        student[b]++;
        node[a].push_back(b);
    }

    for(int i = 1; i<=n; ++i){
        if(student[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        cout << cur << " ";

        for(int i = 0; i< (int)node[cur].size(); ++i){
            int next = node[cur][i];
            student[next]--;
            if(student[next] == 0){
                pq.push(next);
            }
        }

        // for(int i : node[cur]){
        //     student[i]--;
        //     if(student[i] == 0){
        //         pq.push(i);
        //     }
        // }
    }
    return 0;
}