#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    if(a.size() == b.size())    return a < b;
    else return a.size() < b.size();
}
int main()
{
    ios_base::sync_with_stdio(false) ; cin.tie(NULL);
    vector<string> str{"ab","a","abcz","abcd"};
    sort(str.begin(), str.end(), cmp);
    
    for(string s : str){
        cout << s << "\n";
    }
}