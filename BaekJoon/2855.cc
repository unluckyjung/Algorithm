#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num1, num2;

    cin >> num1 >> num2;

    cout << num1 * (num2 % 10) << "\n"
         << num1 * ((num2 % 100) / 10) << "\n"
         << num1 * (num2 / 100) << "\n"
         << num1 * num2 << "\n";

    return 0;
}