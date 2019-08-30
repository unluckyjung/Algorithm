#include <bits/stdc++.h>
using namespace std;

int main()
{
    //key-value 구조.
    //red-black Tree

    //중복 X 정렬상태
    map<char, int> m;

    m.insert(make_pair('A', 0));
    //  m:(A,0)
    //  key = 4, value = 0

    m['B'] = 1;
    //  m:(B,1)

    cout << m.find('A')->second << endl;
    //A를 key로 두고있는 value를 리턴한다.

    if (auto it = m.find('C') == m.end()) //찾는 값이 없을경우 end()를 리턴한다.
        cout << "NULL!" << endl;

    return 0;
}