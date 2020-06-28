#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    int arr2_Size = arr2[0].size();

    for (int i = 0; i < arr1.size(); ++i) {
        vector<int> tmpVec;
        for (int ii = 0; ii < arr2_Size; ++ii) {
            int ret = 0;
            for (int iii = 0; iii < arr1[i].size(); ++iii) {
                ret += arr1[i][iii] * arr2[iii][ii];
            }
            tmpVec.push_back(ret);
        }
        answer.push_back(tmpVec);
    }

    return answer;
}

int main() {
    vector<vector<int>> input1{ {1, 4},{3, 2},{4, 1} };
    vector<vector<int>> input2{ {3, 3},{3, 3} };
    vector<vector<int>> ans = solution(input1, input2);

    return 0;
}