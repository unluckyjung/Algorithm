#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> r >> c;

    //초콜릿 가로축 자르는수 = r-1
    //초콜릿 세로축 자르는수 = c-1 x 가로축 자르면서 잘라진 초콜릿 갯수 r
    //즉  (r-1) + (c-1) * r
    cout << r * c - 1;

    return 0;
}