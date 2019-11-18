#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	for (int i = 0; i < (int)arr1.size(); ++i) {
		//몇개의 벡터를 지녔는지 확인
		vector<int> tmpvec;
		for (int ii = 0; ii < (int)arr1[i].size(); ++ii) {
			//벡터안에 인자가 몇개 있는지 확인
			tmpvec.push_back(arr1[i][ii] + arr2[i][ii]);
		}
		answer.push_back(tmpvec);
	}

	return answer;
}