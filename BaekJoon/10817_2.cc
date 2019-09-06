#include <bits/stdc++.h>
using namespace std;

int arr[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 2; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + sizeof(arr) / sizeof(int));
    cout << arr[1];

    return 0;
}