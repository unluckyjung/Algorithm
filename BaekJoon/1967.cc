#include <bits/stdc++.h>
#define pp pair<int, int>
#define MAX 100002

using namespace std;

vector<pp> node[MAX];
int dist[MAX];
bool visit[MAX];

int n;

queue<int> q;

int bfs(int cmd){
    int ret_dist = 0;
    int ret_node = 0;

    while(!q.empty()){
        int cur_node = q.front(); q.pop();

        for(auto nxt : node[cur_node]){
            int nxt_node = nxt.first;
            int nxt_weight = nxt.second;

            if(visit[nxt_node]) continue;
            visit[nxt_node] = true;
            dist[nxt_node] = dist[cur_node] + nxt_weight;

            if(ret_dist < dist[nxt_node]){
                ret_dist = dist[nxt_node];
                ret_node = nxt_node;
            }
            q.push(nxt_node);
        }
    }

    if(cmd) return ret_node;
    else return ret_dist;
}

void solve() {
    const int root = 1;

    visit[root] = true;
    q.push(root);
    int start = bfs(1);

    memset(dist, 0 , sizeof(dist));
    memset(visit, false, sizeof(visit));

    visit[start] = true;
    q.push(start);

    cout << bfs(0);
}

void input() {
    cin >> n;
    for(int i = 1 ; i< n ; ++i){
        int a, b, weight;
        cin >> a >> b >> weight;

        node[a].push_back({b, weight});
        node[b].push_back({a, weight});
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);  cout.tie(NULL);
   freopen("input.txt", "r", stdin);

   input();
   solve();

   return 0;
}