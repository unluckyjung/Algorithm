#include <bits/stdc++.h>
#include <regex>

using namespace std;

string str, find_str;

#if 01
void Solve() {
    int answer = 0, idx = 0;
    while(1) {
        int nxt = str.find(find_str, idx);
        if (nxt == -1) break;
        idx = nxt + (int)find_str.size();
        answer++;
    }

    cout << answer << "\n";
}

#else
// regex solve
void Solve() {
    regex reg(find_str);
    const sregex_iterator end;
    sregex_iterator it(str.begin(), str.end(), reg);
    
    int answer = 0;
    while (it != end) {
        answer++;
        it++;
    }
    cout << answer << "\n";
}
#endif


void Input() {
    getline(cin, str);
    getline(cin, find_str);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    Input();
    Solve();

    return 0;
}