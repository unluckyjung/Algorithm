#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false) ; cin.tie(NULL);

    int arr[] = {1, 3, 8, 2, 9, 2, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; ++i)
    {
        for (int ii = 0; ii < n - 1; ++ii)
        {
            if(arr[ii] > arr[ii+1])   swap(arr[ii],arr[ii+1]);
        }
    }

    for(int i: arr){
        cout << i <<" ";
    }
    return 0;
}