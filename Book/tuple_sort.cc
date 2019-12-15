#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<tuple<int,int,int>>v;

    v.push_back({1,2,5});
    v.push_back({1,2,3});
    //old compiler
    //v.push_back(make_tuple(1,2,5));

    sort(v.begin(), v.end());

    for(auto it : v){
        cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << "\n";
    }

    return 0;
}