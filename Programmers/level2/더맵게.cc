#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> vec, int K) {
	priority_queue<int, vector<int>, greater<int>> pq;
	int answer = 0;

	while (!vec.empty()) {
		pq.push(vec.back());
		vec.pop_back();
	}

	while (pq.top() < K) {
		int n1 = pq.top();	pq.pop();
		if (pq.empty())	return -1;

		int n2 = pq.top();	pq.pop();
		pq.push(n1 + n2 * 2);
		answer++;
	}
	return answer;
}