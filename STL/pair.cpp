#include <bits/stdc++.h>
using namespace std;

int main()
{
    //  2개의 데이터를 저장할 수 있다.
    pair<int, char> p;
    
    p = make_pair(1,'A');
    //  make_pair를 사용해서 데이터를 넣어줌.
    
    cout << p.first <<endl;
    //  p.first로 p의 첫번째 원소 접근.
    
    p.second = 'B';
    cout << p.second <<endl;

    return 0;
}