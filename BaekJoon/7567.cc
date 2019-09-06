#include <bits/stdc++.h>
using namespace std;

void height(string &dish)
{
    // if ((dish[0] != '(') && (dish[0] != ')'))
    // {
    //     cout << 0;
    //     return;
    // }
    int height = 10;
    int len = dish.size();
    for (int i = 0; i < len - 1; ++i)
    {
        if (dish[i] == dish[i + 1])
        {
            height += 5;
        }
        else
        {
            height += 10;
        }
    }
    cout << height;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string dish;
    cin >> dish;
    height(dish);

    return 0;
}