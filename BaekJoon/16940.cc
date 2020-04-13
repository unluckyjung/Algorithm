#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

vector<int> node[100002];
queue<int> input_q, bfs_q;

int visit[100002];
int n;

bool bfs(){

    while(!bfs_q.empty()){
        int cur = bfs_q.front(); bfs_q.pop();

        unordered_set<int> s;

        for(int connect_node : node[cur]){
            if(visit[connect_node]) continue;
            visit[connect_node] = true;
            s.insert(connect_node);
            //  bfs_q.push(maybe_connect);
            //  이렇게 넣어버리고 한번에 처리하면, BFS 순서가 꼬여버린다.

        }

        for(int i = 0; i < (int)s.size(); ++i){
            if(input_q.empty()) return false;

            int maybe_connect = input_q.front(); input_q.pop();
            if(s.find(maybe_connect) == s.end()) return false;
            bfs_q.push(maybe_connect);
            //  fixed : input_q의 순서에 따라가야 하기 떄문에 
            // 있는지 확인하고, 있는 경우에 bfs_q에 넣는다. 
        }
    }

    return true;
}



bool solve() {
    int start = input_q.front(); input_q.pop();
    if(start != 1) return false;

    visit[start] = true;
    bfs_q.push(start);

    return bfs();
}

void input() {
    cin >> n;
    int a, b;
    for(int i = 0; i < n - 1; ++i){
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    int num;
    for(int i = 0; i < n; ++i){
        cin >> num;
        input_q.push(num);
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);  cout.tie(NULL);
   freopen("input.txt", "r", stdin);

   input();

   if(solve()) cout << 1 << "\n";
   else cout << 0 << "\n";

   return 0;
}