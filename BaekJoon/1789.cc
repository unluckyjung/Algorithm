#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long num, sum = 0, i;
    int count = 0;
    cin >> num;

    for (i = 1; i <= LLONG_MAX; ++i)
    {
        sum += i;
        count++;
        //결국 최고 많이 나올 수 있는경우가 1+2+3+4......임
        if (sum > num)
        {
            cout << count - 1;
            return 0;
        }
    }

    return 0;
}