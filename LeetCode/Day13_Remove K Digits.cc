#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (char ch : num) {
            while (!ans.empty() and ch < ans.back() and k > 0) {
                ans.pop_back();
                k--;
            }
            if (ans.empty() and ch == '0') continue;
            ans.push_back(ch);
        }
        while (!ans.empty() and k > 0) {
            ans.pop_back();
            k--;
        }
        if (ans.empty()) return "0";
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    string num = "1200";
    int k  = 1;

    Solution answer;
    cout << answer.removeKdigits(num, k) << "\n";

    return 0;
}