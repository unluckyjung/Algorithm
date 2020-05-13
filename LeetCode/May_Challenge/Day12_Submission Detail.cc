#include <bits/stdc++.h>
using namespace std;

#if 0
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int n = nums.size() - 1;
		if (n == 0) return nums[0];

		int s = 0, e = n;

		while (s <= e) {
			int diff_cnt = 0;
			int mid;
			mid = s + (e - s) / 2;

			if (mid == 0) {
				diff_cnt++;
				if (nums[mid] != nums[mid + 1]) diff_cnt++;
			}
			else if (mid == n) {
				diff_cnt++;
				if (nums[mid] != nums[mid - 1]) diff_cnt++;
			}
			else {
				if (nums[mid] != nums[mid - 1]) diff_cnt++;
				if (nums[mid] != nums[mid + 1]) diff_cnt++;
			}

			if (diff_cnt == 2) return nums[mid];
			else {
				if (mid % 2 != 0) {
					if (nums[mid] == nums[mid - 1]) s = mid + 1;
					else e = mid - 1;
				}
				else {
					if (nums[mid] == nums[mid + 1]) s = mid + 1;
					else e = mid - 1;
				}
			}
		}
		return -1;
	}
};

#elif 01
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int n = nums.size() - 1;
		if (n == 0) return nums[0];
		int s = 0, e = n;
		int mid;
		while (s <= e) {
			mid = s + (e - s) / 2;
			if (s == e) return nums[mid];
			if (mid % 2 == 0) {
				if (nums[mid] == nums[mid + 1]) s = mid + 2;
				else if (nums[mid] == nums[mid - 1]) e = mid - 2;
				else return nums[mid];
			}
			else {
				if (nums[mid] == nums[mid - 1]) s = mid + 1;
				else e = mid - 1;
			}
		}
		return -1;
	}
};
#endif
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	Solution sol;
	vector<int> vec{ 1,2,2,3,3 };
	cout << sol.singleNonDuplicate(vec);

	return 0;
}