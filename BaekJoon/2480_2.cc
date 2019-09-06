#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];

    if (arr[0] == arr[1] && arr[0] == arr[2])
    {
        cout << 10000 + arr[0] * 1000;
    }
    else if (arr[0] == arr[1] || arr[1] == arr[2])
    {
        cout << 1000 + arr[1] * 100;
    }
    else if (arr[0] == arr[2])
    {
        cout << 1000 + arr[0] * 100;
    }
    else
    {
        cout << max(max(arr[0], arr[1]), arr[2]) * 100;
    }

    return 0;
}