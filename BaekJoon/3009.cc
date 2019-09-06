#include <bits/stdc++.h>
using namespace std;

int arr1[3];
int arr2[3];

int arr1_2[1000];
int arr2_2[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 3; i++)
    {
        cin >> arr1[i] >> arr2[i];
        arr1_2[arr1[i]]++;
        arr2_2[arr2[i]]++;
    }

    for (int i = 0; i < 3; i++)
    {
        if (arr1_2[arr1[i]] != 2)
        {
            cout << arr1[i] << " ";
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (arr2_2[arr2[i]] != 2)
        {
            cout << arr2[i];
        }
    }
    return 0;
}