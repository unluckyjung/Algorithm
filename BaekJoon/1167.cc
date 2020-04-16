#include <bits/stdc++.h>
#define pp pair<int, int>

using namespace std;

vector<pp> node[100002];
int dist[100002];
bool visit[100002];
int n;

queue<int> q;

int bfs(int i){

    int ret_dist = 0;
    int ret_node = 0;

    while(!q.empty()){
        auto cur_node = q.front(); q.pop();

        for(auto nxt : node[cur_node]){
            int nxt_node = nxt.first;
            int nxt_dist = nxt.second;

            if(visit[nxt_node]) continue;
            visit[nxt_node] = true;
            dist[nxt_node] = dist[cur_node] + nxt_dist;

            if(ret_dist < dist[nxt_node]){
                ret_dist = dist[nxt_node];
                ret_node = nxt_node;
            }

            q.push(nxt_node);
        }
    }

    if(i) return ret_node;
    else return ret_dist;
}

void solve() {
    visit[1] = true;
    q.push(1);
    int start = bfs(1);

    memset(dist, 0, sizeof(dist));
    memset(visit, false, sizeof(visit));

    visit[start] = true;
    q.push(start);

    cout << bfs(0);
}

void input() {
    cin >> n;

    int node_num;
    for (int i = 0; i < n; ++i){
        cin >> node_num;
        int a, b;
        while(1){
            cin >> a;
            if(a == -1) break;
            cin >> b;
            node[node_num].push_back({a,b});
        }
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