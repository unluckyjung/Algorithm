#include<bits/stdc++.h>
using namespace std;
char arr[100000];
int main() {
	stack<char> Left;
	stack<char> Right;
	scanf("%s", arr);
	
	int len = strlen(arr);
	//strlen이 시간을 엄청 잡아먹는다. loop문에 절대 쓰지 않길.
	for (int i = 0; i < len; ++i) {
		Left.push(arr[i]);
	}

	int num;
	scanf("%d", &num);
	while (num--) {
		char cmd;
		scanf(" %c", &cmd);
		if (cmd == 'L') {
			if (!Left.empty()) {
				Right.push(Left.top());
				Left.pop();
			}
		}
		else if (cmd == 'D') {
			if (!Right.empty()) {
				Left.push(Right.top());
				Right.pop();
			}
		}
		else if (cmd == 'B') {
			if (!Left.empty()) {
				Left.pop();
			}
		}
		else if (cmd == 'P') {
			char input;
			scanf(" %c", &input);
			Left.push(input);
		}
	}

	int l_size = Left.size();
	//i < Left.size() 를하면, loop 돌떄마다 크기가 바뀌여서 하면 안됨.
	//for (int i = 0; i < l_size; ++i) {
	//	Right.push(Left.top());
	//	Left.pop();
	//}

	while (!Left.empty()) {
		Right.push(Left.top());
		Left.pop();
	}

	while (!Right.empty()) {
		printf("%c", Right.top());
		Right.pop();
	}

	//STACK은 가장 가까운것을 O(1)만에 찾을 수 있다.
	//STACK은 가장 가까운것을 찾을때 의미가 있다!!
	return 0;
}