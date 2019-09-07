#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int len = s.size();

    for (int i = 1; i < len / 2; ++i)   //자를 문자열 길이
    {
        for (int j = 1; j < len / 2; ++j)
        {
            string temp = s.substr(i, j);
            for (int z = j; z < j; ++z)
            {
                string str_compare = s.substr(j + 1, j + 1 + j);
            }
        }
    }

    return 0;
}