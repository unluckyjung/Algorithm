#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int maxSelect = nums.size() / 2;
    set<int> s(nums.begin(), nums.end());

    answer = min((int)s.size(), maxSelect);

    return answer;
}

int main() {

    vector<int> input{ 3,3,3,2,2,4 };
    cout << solution(input);

    return 0;
}