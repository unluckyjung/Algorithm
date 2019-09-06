#include <bits/stdc++.h>
using namespace std;

int main()
{
    //key-value 구조.
    //red-black Tree

    //중복 X 정렬상태
    map<char, int> m;

    m.insert(make_pair('A', 100));
    //  m:(A,0)
    //  key = 4, value = 0

    m['B'] = 200;
    //  m:(B,1)

    cout << m.find('A')->second << endl;
    //A를 key로 두고있는 value를 리턴한다.

    if (auto it = m.find('C') == m.end()) //찾는 값이 없을경우 end()를 리턴한다.
        cout << "NULL!" << endl;

    cout << m['C'] << endl; //이런식으로 없는 Key값에 대해서 참조를 해버리면, value값이 0으로 자동으로 생성된다.

    if (auto it = m.find('C') != m.end()) //C가 존재한다고 나온다.
        cout << "C is exist!" << endl;

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}