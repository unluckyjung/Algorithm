#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	queue<int> q;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		q.push(i);
	}
	printf("<");
	for (int i = 0; i < n - 1; ++i) {   //마지막 사람은 굳이 이 작업을 안해줘도 상관없으니 n-1회 
		for (int j = 0; j < m - 1; ++j) {
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>\n", q.front());
	return 0;
}