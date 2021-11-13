class Solution {
public:
    void reverseString(vector<char> &s) {
      int sSize = s.size();

      for (int i = 0; i < sSize / 2; ++i) {
        swap(s[i], s[sSize - i - 1]);
      }
    }
};