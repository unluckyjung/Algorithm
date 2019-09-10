#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int count;
    int player;
    cin >> count;

    while(count--){

        map<int, string> info;

        int price;
        string name;

        cin >> player;
        while(player--){
            cin >> price >> name;
            info[price] = name;
        }
        cout << info.rbegin()->second <<"\n";
    }
    return 0;
}