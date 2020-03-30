#include <bits/stdc++.h>
using namespace std;

vector<int> node[502];
bool visit[502];

int n, m;
int answer;

void dfs(int cur, int depth){
    if(depth == 2)return;

    for(auto next : node[cur]){
        if(!visit[next]){
            visit[next] = true;
            answer++;
        }
        dfs(next, depth +1);
    }
}
void solve(){
    visit[1] = true;
    dfs(1, 0);
    cout << answer <<"\n";
}

void input(){
    cin >> n >> m;

    int a, b;
    while(m--){
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
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