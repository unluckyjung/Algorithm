#include<bits/stdc++.h>
using namespace std;

bool broken[10];

int want;
int broken_n;
int answer;

bool check(int c){
    string cs = to_string(c);
    for(int i = 0 ; i<cs.size(); ++i){
        int check_num = cs[i]-'0';
        if(broken[check_num])     return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> want >> broken_n;
    
    while(broken_n--){
        int n;
        cin >> n;
        broken[n] = true;
    }

    answer = abs(want - 100);

    for(int i = 0 ; i<= 1000000; ++i){
        int c = i;
        if(check(c))continue;
        int push = abs(want - c) + to_string(c).size();

        answer = min(answer, push);
    }

    cout << answer <<"\n";

    return 0;
}