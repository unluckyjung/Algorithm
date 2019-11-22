#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int time = 0, index = 0;
	priority_queue<int> pq;

	while (1) {
		time++; stock--;
		if (time == k)break;

		if (dates[index] == time) {
			pq.push(supplies[index]);
			index++;
		}
		if (stock == 0) {
			stock += pq.top();	pq.pop();
			answer++;
		}
	}

	return answer;
}