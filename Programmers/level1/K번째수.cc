#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {

	vector<int> answer;

	for (int i = 0; i < (int)commands.size(); ++i) {
			int start = commands[i][0] -1;
			int cut = commands[i][1];
			int find_num = commands[i][2]-1;

			vector<int> vec;
			for (int ii = start; ii < cut; ++ii) {
				vec.push_back(array[ii]);
			}
			sort(vec.begin(), vec.end());
			answer.push_back(vec[find_num]);
	}

	return answer;
}