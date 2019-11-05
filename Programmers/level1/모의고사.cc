#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> human1{ 1,2,3,4,5 };
vector<int> human2{ 2,1,2,3,2,4,2,5 };
vector<int> human3{ 3,3,1,1,2,2,4,4,5,5 };

int h1, h2, h3;
int answer_count[4];


vector<int> solution(vector<int> answers) {

	vector<int> ans;

	int len = answers.size();
	int MAX = 0;

	for (int i = 0; i < len; ++i) {

		if (answers[i] == human1[i % 5]) answer_count[1]++;
		if (answers[i] == human2[i % 8]) answer_count[2]++;
		if (answers[i] == human3[i % 10]) answer_count[3]++;

	}

	MAX = *max_element(answer_count, answer_count + 4);

	for (int i = 1; i <= 3; ++i) {
		if (answer_count[i] == MAX) ans.push_back(i);
	}

	return ans;
}