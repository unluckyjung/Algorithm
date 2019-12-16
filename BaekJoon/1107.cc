#include <bits/stdc++.h>
using namespace std;

bool broken_button[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
string want;
int broken;

int ans = INT_MAX;

bool broken_check(const string &s){
    for(char c : s){
        if(broken_button[c-'0'])    return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> want;
    cin >> broken;

    while (broken--)
    {
        int broken_num;
        cin >> broken_num;
        broken_button[broken_num] = true;
    }

    int want_int = stoi(want);
    //ans = min(ans, abs(100 - want_int));

    string up = want;
    int up_cnt = 0;
    string down = want;
    int down_cnt= 0;

    while(broken_check(up)){
        up = to_string(stoi(up) + 1);
        up_cnt;
    }

    while(broken_check(down)){
        down = to_string(stoi(down) - 1);
        down_cnt;
    }


    ans = min({ans, abs(100 - want_int),up_cnt, down_cnt});

    cout << ans;

    return 0;
}