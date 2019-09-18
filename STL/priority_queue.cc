#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int> pq_up;
	//priority_queue<int, vector<int> , less<int>> pq_up;
	//위와 완전히 동일하다.

	pq_up.push(5);
	pq_up.push(23);
	pq_up.push(53);
	pq_up.push(17);
	cout << pq_up.top() << "\n";	//	53

	priority_queue<int, vector<int>, greater<int>> pq_down;
	//greater를 주어서, 오름차순 정렬.

	pq_down.push(5);
	pq_down.push(23);
	pq_down.push(53);
	pq_down.push(17);
	cout << pq_down.top() << "\n";	//	5
    //front()가 아닌 top()이다.
	return 0;
}