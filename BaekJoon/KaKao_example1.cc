#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<vector<int>> v)
{
    vector<int> ans(2, 0);

    if (v[0][0] == v[1][0] && v[0][1] == v[2][1])
    {
        ans[0] = v[2][0]; //x3
        ans[1] = v[1][1]; //y2
    }
    else if (v[0][0] == v[2][0] && v[0][1] == v[1][1])
    {
        ans[0] = v[1][0]; //x2
        ans[1] = v[2][1]; //y3
    }
    else if (v[0][0] == v[1][0] && v[1][1] == v[2][1])
    {
        ans[0] = v[2][0]; //x3
        ans[1] = v[0][1]; //y1
    }
    else if (v[1][0] == v[2][0] && v[0][1] == v[1][1])
    {
        ans[0] = v[0][0]; //x1
        ans[1] = v[2][1]; //y3
    }
    else if (v[0][0] == v[2][0] && v[1][1] == v[2][1])
    {
        ans[0] = v[1][0]; //x2
        ans[1] = v[0][1]; //y1
    }
    else if (v[1][0] == v[2][0] && v[0][1] == v[2][1])
    {
        ans[0] = v[1][0]; //x1
        ans[1] = v[1][1]; //y2
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

    // cout << solution(v);

    // cout << v[0][1];

    // vector<int> vec1, vec2, vec3, vec4;
    // vec1.push_back(1);
    // vec1.push_back(4);

    // v.push_back(vec1);

    // cout << v[0][0];
    // cout << v[0][1];

    // for (auto i : v)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j;
    //     }
    // }
    return 0;
}