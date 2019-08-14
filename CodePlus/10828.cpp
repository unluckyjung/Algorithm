#include<bits/stdc++.h>
using namespace std;

int main() {
	unsigned count;
	scanf("%u", &count);
	stack<int> s;	//int형 스택 s를 만든다.

	while (count--) {
		string cmd;	//문자열 선언을 이와 같은 방식으로 쓴다.
		//scanf("%s", cmd);	//string으로 한거는 scanf로 사용불가.
		cin >> cmd;
		if (cmd == "push") {
			int num;
			scanf("%d", &num);
			s.push(num);
		}
		else if (cmd == "top") {
			s.empty() ? printf("-1\n") : printf("%d\n", s.top());
		}
		else if (cmd == "pop") {
			s.empty() ? printf("-1\n") : printf("%d\n", s.top());
			if (!s.empty()) {	//비어잇지 않을경우 0을 리턴함.
				s.pop();	//가장 위의 것을 출력했으니, 이제 지워야함.
			}
		}
		else if (cmd == "size") {
			printf("%d\n",s.size());
		}
		else if (cmd == "empty") {
			printf("%d\n", s.empty());
		}
	}
	return 0;
}