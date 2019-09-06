#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int len = str.size();
    int index = len - 1;
    for (int i = 0; i < len / 2; ++i)
    {
        if (str[i] != str[index - i])
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1;

    return 0;
}