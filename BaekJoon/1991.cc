#include <bits/stdc++.h>
using namespace std;

int lc[28], rc[28];
int n;
const int root = 0;

void post_order(int cur){
    if(lc[cur]) post_order(lc[cur]);
    if(rc[cur]) post_order(rc[cur]);
    cout << char(cur + 'A');
}

void in_order(int cur){
    if(lc[cur]) in_order(lc[cur]);
    cout << char(cur + 'A');
    if(rc[cur]) in_order(rc[cur]);
}

void pre_order(int cur){
    cout << char(cur + 'A');
    if(lc[cur]) pre_order(lc[cur]);
    if(rc[cur]) pre_order(rc[cur]);
}

void solve() {
    pre_order(root);
    cout <<"\n";
    in_order(root);
    cout <<"\n";
    post_order(root);
}

void input() {
    cin >> n;

    char parent;
    for(int i = 0 ; i < n; ++i){
        cin >> parent;
        parent -= 'A';

        char left, right;
        cin >> left >> right;
        if(left != '.') lc[parent] = left - 'A';
        if(right != '.') rc[parent] = right - 'A';
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