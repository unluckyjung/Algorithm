#include <bits/stdc++.h>
using namespace std;

void alcohol(map<int, string> &univ)
{
    auto it = univ.end();
    cout << (--it)->second << "\n";
    //맨뒤 map 출력.

    univ.clear();
    //map 모든 원소 삭제.
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;
    while (count--)
    {
        int count2;
        cin >> count2;

        map<int, string> map;

        while (count2--)
        {
            string name;
            int num;
            cin >> name >> num;
            map.insert(make_pair(num, name));
            //map[num] = name;
        }
        alcohol(map);
    }

    return 0;
}