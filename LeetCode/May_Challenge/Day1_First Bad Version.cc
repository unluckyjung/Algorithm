// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#if 01
class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n;
        int mid, answer = -1;
        
        while(s <= e){       
            mid = s + (e - s) / 2;              

            if(isBadVersion(mid)) {
                answer = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }      

        return answer;
    }
};

#else
class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n;
        int mid;
        
        while(s <= e){       
            if(s == e) return s;

            mid = s + (e - s) / 2;              

            if(isBadVersion(mid)) e = mid;
            else s = mid + 1;
        }      
        

        return -1;
    }
};

#endif