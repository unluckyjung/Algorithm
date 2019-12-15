#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> &p1, const pair<int,int> &p2){
    if(p1.first == p2.first) return p1.second > p2.second;
    else return p1.first < p2.first;
}
int main()
{
    ios_base::sync_with_stdio(false) ; cin.tie(NULL);
    vector<pair<int, int>> p;
    p.push_back({4,2});
    p.push_back({3,10});
    p.push_back({2,8});
    p.push_back({4,15});
    int cur = 0;
    int score = 0;

    sort(p.begin(), p.end());

    for(auto it : p){
        cur += it.first;
        score += it.second - cur;
    }

    cout << score << "\n";
    return 0;
}