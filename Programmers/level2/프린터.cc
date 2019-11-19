#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

//벡터의 숫자별 가중치를 배열에 저장시켜둔다.
//큐에다가 순서대로 넣는다.
//큐 전체를 탐색하는데, 우선순위가 높은게 있으면, 다시 큐에 넣는다.
//본인의 가중치가 제일 크다면 cnt를 증가시키고, pop한다.
//만약 pop한것이 내가 원하는 것이면 answer에 cnt를 리턴하고 끝낸다.

int arr[101];

int solution(vector<int> priorities, int location) {
	int answer = 0;

	queue<int> q;
	
	for (int i = 0; i < (int)priorities.size(); ++i) {
		arr[i] = priorities[i];
		q.push(i);
	}
	int MAX = *max_element(arr, arr + sizeof(arr) / sizeof(int));
	
	int cnt = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (arr[cur] < MAX) q.push(cur);
		else {
			if (cur == location) return cnt;
			arr[cur] = 0;
			MAX = *max_element(arr, arr + sizeof(arr) / sizeof(int));
			cnt++;
		}
	}

	//return answer;
}

int main() {
	vector<int> vec{ 1,1,3,1 };
	int lo = 0;

	cout << solution(vec, lo);
	return 0;
}