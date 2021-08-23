class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n;
        int answer = INT_MAX;
        int mid;
        
        while(s <= e){       
            mid = s + (e - s) / 2;              

            if(isBadVersion(mid)) {
                e = mid - 1;
                answer = min(answer, mid);
            } else {
                s = mid + 1;
            }
        }      
        

        return answer;
    }
};