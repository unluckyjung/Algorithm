#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> vec1;

    //vector<Node> vec2;    구조체 형식을 저장하는 동적배열가능

    int n = 2;
    int m = 3;
    vector<int> vec4(n);    //크기를 n으로 설정.
    vector<int> vec5(5, 1); //1 1 1 1 1

    vector<vector<int>> vec6(n, vector<int>(m, 0));
    //n x m 크기의 2차원 백터 선언. 0으로 초기화.

    vec1.push_back(1);
    vec1.pop_back();
    cout << vec1.size() << endl;

    vec1.resize(m);
    //vec1 크기 재설정.

    vec1.clear();
    //vec1 모든 원소 삭제

    vec1.begin();
    //첫 원소의 주소.
    vec1.end();
    //마지막 원소의 "다음" 주소.

    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);

    vector<int> copy_vec = vector<int>(vec1.begin() + 2, vec1.end());
    for (int i : copy_vec)
        cout << i << endl;
    
    //vec1의 2번째 인덱스부터 복사하여 copy_vec에 넣음.
    return 0;
}