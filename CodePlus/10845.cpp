#include<bits/stdc++.h>
using namespace std;
int main() {
	queue<int> q;
	string s;
	int num;
	
	scanf("%d", &num);
	while (num--) {
		cin >> s;
		if (s == "push") {
			int n;
			scanf("%d", &n);
			q.push(n);
		}
		else if (s == "pop") {
			if (!q.empty()) {
				printf("%d\n", q.front());
				q.pop();
			}
			else {
				printf("-1\n");
			}
		}
		else if (s == "size") {
			printf("%d\n", q.size());
		}
		else if (s == "empty") {
			if (q.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (s == "front") {
			if (!q.empty()) {
				printf("%d\n", q.front());
			}
			else {
				printf("-1\n");
			}
		}
		else if (s == "back") {
			if (!q.empty()) {
				printf("%d\n", q.back());
			}
			else {
				printf("-1\n");
			}
		}
	}
	return 0;
}