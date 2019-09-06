#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string oper;

    string num1, num2;
    cin >> num1;
    cin >> oper;
    cin >> num2;

    if (oper == "*")
    {
        int len = num2.size() - 1;
        while (len--)
        {
            num1 = num1 + "0";
        }
        cout << num1;
    }

    else if (oper == "+")
    {
        if (num1.size() > num2.size())
        {
            int len = num1.size() - num2.size();
            if (num1[len] == '0')
            {
                num1[len] = '1';
            }
            else
            {
                num1[len] = '2';
            }
            cout << num1;
        }
        else
        {
            int len = num2.size() - num1.size();
            if (num2[len] == '0')
            {
                num2[len] = '1';
            }
            else
            {
                num2[len] = '2';
            }
            cout << num2;
        }
    }

    return 0;
}