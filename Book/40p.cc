#include <bits/stdc++.h>
using namespace std;
int n;
int arr[] = {-1, 2, 4, -3, 5, 2, -5, 2};

void solution1()
{
    int best = 0;
    for (int a = 0; a < n; ++a)
    {
        int sum = 0;
        for (int b = a; b < n; ++b)
        {
            sum += arr[b];
            best = max(best, sum);
        }
    }
    cout << best << "\n";
    return;
}

void solution2()
{
    int best = 0, sum = 0;
    for (int k = 0; k < n; ++k)
    {
        sum = max(arr[k], arr[k] + sum);
        best = max(best, sum);
    }
    cout << best << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = sizeof(arr) / sizeof(int);
    solution1();
    solution2();

    return 0;
}