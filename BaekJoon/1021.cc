#include <bits/stdc++.h>
using namespace std;

//1021 회전하는 큐
//dq라는데 list로 풀었음..
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	list<int>l;

	for (int i = 1; i <= N; ++i) {
		l.push_back(i);
	}

	auto it = l.begin();

	int sum = 0;
	while (M--) {
		int num;
		cin >> num;

		int num1 = 0;
		int num2 = 0;

		auto it1 = it;	//앞으로 돌놈
		auto it2 = it;	//뒤로 놀놈.

		for (; ; it1++) {

			if (it1 == l.end()) it1 = l.begin();
			//끝에 닿을경우, 맨앞으로 돌려보냄 end()는 참조 불가 하므로 여기서 검사.
			if (*it1 == num) {
				break;	//찾았을 경우 break.
			}
			num1++;	//거리.
		}

		for (; ; it2--) {
			//뒤로 도는경우.
			//만약 it2에 end가 들어와도 --하고 들어오기 때문에, 맨뒤의 원소부터 탐색
			if (*it2 == num) {	//begin일 경우에도 참조 가능. 여기서 검사.
				break;
			}
			if (it2 == l.begin()) it2 = l.end();	//begin일경우 맨뒤로 돌려보냄.
			//if (it2 == --l.begin()) it2 = --l.end();	
			//이전엔 이런식으로 헀는데 --begin()자체가 말이 안되는 경우임.
			//rend()의 경우도 rbegin()시작이 아니라 사용 불가.
			num2++;
		}

		if (num1 < num2) {
			it = l.erase(it1);
			if (it == l.end()) it = l.begin();
			sum += num1;
		}
		else {
			it = l.erase(it2);
			if (it == l.end()) it = l.begin();
			sum += num2;
		}
	}
	cout << sum;

	return 0;
}