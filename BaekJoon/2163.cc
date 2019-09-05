#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n1, n2;
    cin >> n1 >> n2;

    int count1 = 0;
    for (int i = n1; i != 1; i--, count1++);

    int count2 = 0;
    for (int i = n2; i != 1; i--, count2++);

    cout << count1 + count2 * n1;
    return 0;
}