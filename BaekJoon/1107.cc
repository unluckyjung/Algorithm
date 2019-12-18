#include <bits/stdc++.h>
using namespace std;

int want_c;
int m;
int answer = INT_MAX;
bool broken[10];

void broken_set()
{
    cin >> m;
    while (m--)
    {
        int broken_num;
        cin >> broken_num;
        broken[broken_num] = true;
    }
}

int get_input_len(const int &input)
{
    string c = to_string(input);
    int c_size = c.size();

    for (int i = 0; i < c_size; ++i)
    {
        if (broken[c[i]-'0'])
            return 0;
    }
    return c_size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> want_c;
    broken_set();

    answer = abs(want_c - 100);
    for (int i = 0; i <= 1000000; ++i)
    {
        int c = i;
        int c_len = get_input_len(c);
        if (c_len)
        {
            int push = c_len + abs(want_c-c);
            answer = min(answer, push);
        }
    }
    cout << answer <<"\n";
    return 0;
}