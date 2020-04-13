#include <bits/stdc++.h>
#define pp pair<int,int>

using namespace std;

vector<int> node[3002];
int answer[3002];
bool incycle[3002];
bool visit[3002];
int n;

queue<pp> q;

void print_answer(){
    for(int i = 1; i<=n; ++i) 
        cout << answer[i] << " ";
}

void Init(){
    while(!q.empty()) q.pop();
    memset(visit, false, sizeof(visit));
}

int bfs(){
    while(!q.empty()){
        auto cur = q.front();   q.pop();
        int cur_node = cur.first;
        int cur_dist = cur.second;

        for(auto nxt : node[cur_node]){
            if(visit[nxt])continue;
            if(incycle[nxt]) return cur_dist;
            
            visit[nxt] = true;
            q.push({nxt, cur_dist + 1});
        }
    }
    return -1;
}

//TODO : 가지치기
int dfs(int cur, int before){
    for(auto nxt : node[cur]){
        if(nxt == before) continue;
        if(visit[nxt]){
            incycle[nxt] = true;
            incycle[cur] = true;
            return nxt;
        }
        visit[nxt] = true;
        int tmp = dfs(nxt, cur);
        if(tmp == cur or tmp == -1) return -1;
        if(tmp == -2) continue;
        incycle[cur] = true;
        return tmp;
    }
    return -2;
}

void solve() {
    visit[1] = true;
    dfs(1,0);
    for(int i = 1; i <=n; ++i){
        if(incycle[i]) answer[i] = 0;
        else{
            //TODO : 초기화, BFS를 하지말고, 한번에 돌릴수 있는 방법을 고안.
            Init();
            visit[i] = true;
            q.push({ i, 1 });
            answer[i] = bfs();
        }
    }
    print_answer();
}

void input() {
    cin >> n;
    int a, b;
    for(int i = 0 ; i<n; ++i){
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);  cout.tie(NULL);
   //freopen("input.txt", "r", stdin);

   input();
   solve();

   return 0;
}