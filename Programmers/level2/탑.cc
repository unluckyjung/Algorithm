#include <string>
#include <vector>

using namespace std;

//pair형 vector 만들어둠.
//heihgts를 0부터 끝까지 돌게만듬.


//vector가 비지 않았을경우
//맨뒤에 있는값이 자기보다 크다면, 해당 타워 index를 답에 넣고, 자신도 벡터에 들어감. 그리고 종료.
//맨뒤에 있는값이 자기보다 작다면, 해당 타워를 pop시켜버림. 어차피 뒤에서 오는것은 이 타워가 다 가로막음.
//그리고 앞의 타워를 더 찾아봄.

//vector가 비어있으면 자기보다 큰놈이 없었으므로 0을 답에 넣고 자기가 vector에 들어감.


vector<int> solution(vector<int> heights) {
	vector<pair<int, int>> tower;	//number +1 , height
	vector<int> answer;

	for (int i = 0; i < (int)heights.size(); ++i) {

		while (!tower.empty()) {
			if (tower.back().second > heights[i]) {
				answer.push_back(tower.back().first);
				tower.push_back({ i + 1, heights[i] });
				break;
			}
			else {
				tower.pop_back();
			}
		}

		if (tower.empty()) {
			answer.push_back(0);
			tower.push_back({ i + 1, heights[i] });
		}
	}

	return answer;
}