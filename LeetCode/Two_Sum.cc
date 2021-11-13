#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pre;
        const auto noExist = pre.end();

		for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int findNum = target - num;

            if (pre.find(findNum) == noExist) pre[nums[i]] = i;
            else return { pre[findNum], i };
        }
        return { -1,-1 };
    }
};

void Solve() {
    Solution sol;
    vector<int> input{ 2,7,11,15 };
    int target = 9;
    
	vector<int>answer = sol.twoSum(input, target);

	for (const int& it : answer) {
		cout << it << " ";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    Solve();

    return 0;
}