#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); ++i) {
		int index = 0;
		bool answer_check = true;
		for (int ii = 0; ii < skill_trees[i].size(); ++ii) {
			int index_find = skill.find(skill_trees[i][ii]);

			if (index_find == -1)continue;
			else if (index_find != index) {
				//맨앞부터 배우는게 아니면, 잘못된 스킬숙련
				answer_check = false;
				break;
			}
			else index++;
		}
		if (answer_check) answer++;
	}

	return answer;
}

int main() {
	string str = "CBD";
	vector<string> vec;
	vec.push_back("BACDE");
	solution(str, vec);
	return 0;
}