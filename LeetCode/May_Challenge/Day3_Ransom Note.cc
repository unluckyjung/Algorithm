#if 0
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        
        for(char ch : magazine){
            m[ch]++;
        }
        
        for(char ch : ransomNote){
            if(m[ch] == 0) return false;
            else m[ch]--;
        }
        return true;
        
    }
};

#else

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int alpa_cnt[27] = { 0, };

		if ((int)ransomNote.size() > (int)magazine.size()) return false;

		for (char ch : magazine) {
			alpa_cnt[ch - 'a']++;
		}

		for (char ch : ransomNote) {
			if (--alpa_cnt[ch - 'a'] < 0) return false;
		}
		return true;

	}
};
#endif