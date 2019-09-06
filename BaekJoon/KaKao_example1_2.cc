#include <bits/stdc++.h>
using namespace std;

char arr1_2[10000001];  //1000000001
char arr2_2[10000001];

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans (2,0);

    for(int i = 0 ; i<3; ++i){
            arr1_2[v[i][0]]++;
    }

    for(int i = 0 ; i<3; ++i){
            arr2_2[v[i][1]]++;
    }


    for (int i = 0; i < 3; i++)
    {
        if (arr1_2[v[i][0]] != 2)
        {
            ans[0] = v[i][0];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (arr2_2[v[i][1]] != 2)
        {
            ans[1] = v[i][1];
        }
    }

    return ans;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> v(3, vector<int>(2));
    v[0] = {1, 4};
    v[1] = {3, 4};
    v[2] = {3, 10};

    vector<int> answer(solution(v));
    for (auto i : answer)
    {
        cout << i << " ";
    }

    return 0;
}