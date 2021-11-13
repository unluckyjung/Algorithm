class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x_diff = coordinates[1][0] - coordinates[0][0];
        int y_diff = coordinates[1][1] - coordinates[0][1];
        
        int pivot_x = coordinates[1][0];
        int pivot_y = coordinates[1][1];
        
        bool is_first = true;
        
        for(const auto &spot : coordinates){
            if(is_first){
                is_first = false;
                continue;
            }
            if((spot[0] - pivot_x) * y_diff != (spot[1] - pivot_y) * x_diff) return false;
        }
        
        return true;
    }
};