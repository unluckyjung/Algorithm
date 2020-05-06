#include <bits/stdc++.h>
#include <regex>
using namespace std;

string str;

void Solve() {
    regex reg("-?[0-9]+");
    sregex_iterator it(str.begin(), str.end(), reg);
    sregex_iterator it_end;

    bool minus_flag = false;
    int sum = 0;

    while (it != it_end) {
        int num = stoi((*it).str());
        if (!minus_flag and num < 0) minus_flag = true;

        if (minus_flag) sum -= abs(num);
        else sum += num;

        it++;
    }
    cout << sum << "\n";
}

void Input() {
    cin >> str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    Input();
    Solve();

    return 0;
}