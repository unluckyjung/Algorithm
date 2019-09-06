#include <bits/stdc++.h>
using namespace std;
int human[1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;

    cin >> count;

    for (int i = 0; i < count; i++)
    {
        int arr[3];

        cin >> arr[0] >> arr[1] >> arr[2];

        if (arr[0] == arr[1] && arr[0] == arr[2])
        {
            human[i] = 10000 + arr[0] * 1000;
        }
        else if (arr[0] == arr[1] || arr[1] == arr[2])
        {
            human[i] = 1000 + arr[1] * 100;
        }
        else if (arr[0] == arr[2])
        {
            human[i] = 1000 + arr[0] * 100;
        }
        else
        {
            human[i] = max(max(arr[0], arr[1]), arr[2]) * 100;
        }
    }

    sort(human, human + 1000, greater<int>());
    cout << human[0];

    return 0;
}