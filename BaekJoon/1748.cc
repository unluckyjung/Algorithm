#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    cin >> num;

    int n_size = num.size();
    long long ans = 0;
    //int tmp = 1;

    for (int i = 1; i < n_size; ++i)
    {
        ans += i * 9 * (int)pow(10,i-1);
        //tmp *= 10;
    }

    //ans = ans + (stoi(num) - tmp +1) * n_size;
    ans = ans + (stoi(num) - (int)pow(10, n_size -1) +1) * n_size;
    cout << ans <<"\n";

    return 0;
}