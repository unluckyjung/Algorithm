#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int stage_try[200000];
int stage_clear[200000];
int stage_fail[200000];

bool cmp(const pair<double,int> &a, const pair<double, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
	//first second주의
}

vector<int> solution(int N, vector<int> stages) {

	vector<int> answer;

	for (int i = 0; i < (int)stages.size(); ++i) {
		int ret = stages[i];
		for (int ii = 1; ii <= ret; ++ii) {
			stage_try[ii]++;
		}

		for (int ii = 1; ii < ret; ++ii) {
			stage_clear[ii]++;
		}
	}

	for (int i = 1; i <= N; ++i) {
		stage_fail[i] = stage_try[i] - stage_clear[i];
	}

	vector<pair<double, int>> result;
	for (int i = 1; i <= N; ++i) {
		if(stage_try[i] == 0) 	result.push_back({ 0 , i });
		else result.push_back({(double)stage_fail[i]/(double)stage_try[i], i});
		//반드시 double로 바꿔줘야한다.
	}

	sort(result.begin(), result.end(), cmp);

	for (auto it = result.begin(); it != result.end(); ++it) {
		answer.push_back(it->second);
	}

	return answer;
}

int main() {

	vector<int> vec{ 2, 1, 2, 6, 2, 4, 3, 3 };

	vector<int> tmp = solution(5, vec);

	for (auto it : tmp) {
		cout << it << " ";
	}
	return 0;
}