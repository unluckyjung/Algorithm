#include <bits/stdc++.h>
using namespace std;
//백준 문제번호
//https://www.acmicpc.net/problem/

long long tree[3000000];

int n, m, k;

void update_node(int node ,int s, int e , int idx, int data){
    if(s==e){
        tree[node] = data;
        return;
    }
    int mid = (s+e)/2;
    if (idx <= mid) update_node(node * 2, s, mid, idx, data);
    else update_node(node * 2 + 1, mid + 1, e, idx, data);

    tree[node] = tree[node*2] + tree[node*2+1];
}

long long query(int node, int s, int e, int qs, int qe){
    if(qs <= s and e <= qe) return tree[node];
    if(qs >e  or s > qe) return 0;

    int mid = (s+e)/2;
    long long left = query(node*2, s, mid, qs, qe);
    long long right = query(node*2+1, mid+1, e, qs, qe);
    return left + right;
}

void solve(){
    cin >> n >> m >> k;

    for(int i = 1; i<=n; ++i){
        int data; cin >> data;
        update_node(1, 1, n, i, data);
    }

    for(int i = 0; i< m+k; ++i){
        int cmd, b ,c;
        cin >> cmd >> b>> c;
        if(cmd == 1) update_node(1, 1, n, b, c);
        else if(cmd == 2) cout << query(1, 1, n, b, c) <<"\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    solve();

	return 0;
}