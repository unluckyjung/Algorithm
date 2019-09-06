#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<pair<int, string>> pair_vec;

    pair_vec.push_back(make_pair(3, "Hi"));
    pair_vec.push_back(make_pair(30, "Hello"));

    for (auto i : pair_vec)
    {
        cout << i.first << endl;
    }

    for (auto i = pair_vec.begin(); i != pair_vec.end(); ++i)
    {
        cout << i->second << endl;
        //여기서 i는 pair의 iterator이다. 위의경우와 차이를 확실히 알아두자.
    }
    return 0;
}