#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<string> &a)
{
    int n = a.size();
    int ans = 1;
    for (int i = 0; i < n; ++i)
    {
        int cnt = 1;
        for (int ii = 1; ii < n; ++ii)
        {
            if (a[i][ii] == a[i][ii - 1])
                cnt++;
            else
                cnt = 1;

            ans = max(ans, cnt);
        }
        cnt = 1;
        for (int ii = 1; ii < n; ++ii)
        {
            if (a[ii][i] == a[ii - 1][i])
                cnt++;
            else
                cnt = 1;
            ans = max(ans, cnt);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int ii = 0; ii < n; ++ii)
        {
            if (ii + 1 < n)
            {
                swap(a[i][ii], a[i][ii + 1]);
                int temp = check(a);
                ans = max(ans, temp);
                swap(a[i][ii], a[i][ii + 1]);
            }

            if (i + 1 < n)
            {
                swap(a[i][ii], a[i+1][ii]);
                int temp = check(a);
                ans = max(ans, temp);
                swap(a[i][ii], a[i+1][ii]);
            }
        }
    }

    cout << ans <<"\n";
    return 0;
}