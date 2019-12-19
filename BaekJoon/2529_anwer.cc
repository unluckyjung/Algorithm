#include <bits/stdc++.h>
using namespace std;

int n;
char cmd[20];
vector<string> ans;
bool used[10];

bool check(const char &x, const char &y, const char &op){
    if(op == '<')   return x< y;
    else    return x>y;
}

void solve(const int &index, const string &num){
    if(index == n+1){
        ans.push_back(num);
        return;
    }

    for(int i = 0 ; i<=9; ++i){
        if(used[i])continue;
        if(index == 0 or check(num[index-1], i + '0', cmd[index-1])){
            used[i] = true;
            solve(index+1, num + to_string(i));
            used[i] = false;
        }

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0 ; i<n; ++i){
        cin >> cmd[i];
    }

    solve(0, "");
    cout << *max_element(ans.begin(), ans.end()) << "\n";
    cout << *min_element(ans.begin(), ans.end()) << "\n";
    return 0;
}