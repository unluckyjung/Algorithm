#include <bits/stdc++.h>
#include <regex>
using namespace std;

string str, s;

void PPAP_check() {
    string PPAP_checker = "";
    for (int i = 0; i < 4; ++i) {
        PPAP_checker = s.back() + PPAP_checker;
        s.pop_back();
    }
    if (PPAP_checker == "PPAP") s += "P";
    else s += PPAP_checker;
}

bool Solve() {
    for (const char &c : str) {
        s.push_back(c);
        if (s.size() >= 4) PPAP_check();
    }
    if (s == "P" or s == "PPAP") return true;
    else return false;
}

void Input() {
    cin >> str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    Input();
    if (Solve()) cout << "PPAP\n";
    else cout << "NP\n";

    return 0;
}