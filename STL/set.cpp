#include <bits/stdc++.h>
using namespace std;

int main()
{
    //이진트리 생성.
    //중복 X , 정렬되어있음.
    set<int> s;

    s.insert(6);
    s.insert(5);
    s.insert(4);
    
    cout << *s.begin() <<endl;

    if (s.find(6) != s.end())
        cout << "exist!" << endl;
    //없다면 s.end()리턴.

    s.size();
    //저장된 원소의 갯수

    s.erase(++s.begin());
    //2번째 원소 삭제

    s.clear();

    return 0;
}