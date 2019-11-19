#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

//vector를 0부터돈다.
//진행사항 / 스피드를 해서 얼마나 걸리는지 확인한다. 큐에다가 마감 예정시간을 넣는다.

//다음의 것도 진행사항 / 스피드 해서 확인한다.

//만약 해당값이 큐의 front보다 작거나 같다면 큐에 넣는다.
//만약 해당값이 큐보다 크다면 큐의 크기만큼 answer에 넣고, 큐를 비운다음, 해당값을 큐에 넣는다.

//for문이 끝낫는데 큐에 남은게 있다면, 해당 큐의 크기만큼 answer에 넣는다.

queue<int> q;

void queue_clear() {
	while (!q.empty()) {
		q.pop();
	}
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	for (int i = 0; i < (int)progresses.size(); ++i) {
		int finish = (100 - progresses[i]) / speeds[i];
		if ((100 - progresses[i]) % speeds[i] != 0)finish++;

		//cout << finish << " ";
		if (q.empty()) {
			q.push(finish);
		}
		else {
			if (finish <= q.front()) q.push(finish);
			else {
				answer.push_back(q.size());
				queue_clear();
				q.push(finish);
			}	
		}
	}

	if (!q.empty()) {
		answer.push_back(q.size());
	}

	return answer;
}