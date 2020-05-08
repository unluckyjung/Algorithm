#include <bits/stdc++.h>
using namespace std;

#if 00
#define pp pair<int,int>
//Sort
class Solution {
public:
    static bool cmp(const pp& a, const pp& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }

    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (const int& it : nums) {
            m[it]++;
        }

        vector<pp> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), cmp);
        return vec.rbegin()->first;
    }
};

#elseif 
// Major_check
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        const int major_pivot = nums.size() / 2;

        for (const int& it : nums) {
            if (m[it]++ == major_pivot) return it;
        }
        return -1;
    }
};

# else
//Moore Voting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0; int answer = 0;
        
        for (const int& it : nums) {
            if (vote == 0) answer = it;

            if (it == answer) vote++;
            else vote--;
        }
        return answer;
    }
};

#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

	vector<int> vec{ 3,3,4,4 };

    Solution answer;
	cout << answer.majorityElement(vec);

    return 0;
}