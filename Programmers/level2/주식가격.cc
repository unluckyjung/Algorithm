#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (int i = 0; i < prices.size(); ++i) {
		int cur = prices[i];
		int time = 0;
		for (int ii = i + 1; ii < prices.size(); ++ii) {
			time++;
			if (prices[ii] < cur) {
				break;
			}
		}
		answer.push_back(time);
	}
	return answer;
}


vector<int> solution2(vector<int> prices) {

	int size = prices.size();
	vector<int> answer(size);
	vector<int> vec;


	for (int i = 0; i < size; ++i) {
		while (!vec.empty() && prices[i] < prices[vec.back()] ) {
			answer[vec.back()] = i - vec.back();	
			vec.pop_back();
		}
		vec.push_back(i);
	}

	while (!vec.empty()) {
		answer[vec.back()] = size - vec.back() - 1;
		vec.pop_back();
	}

	return answer;
}


vector<int> solution3(vector<int> prices) {
	int size = prices.size();
	vector<int> answer(size);
	stack<int> s;

	for (int i = 0; i < size; ++i) {

		while (!s.empty() && prices[i] < prices[s.top()]) {
			answer[s.top()] = i - s.top();
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		int cur = s.top();
		answer[cur] = size - 1 - cur;
		s.pop();
	}
	return answer;
}