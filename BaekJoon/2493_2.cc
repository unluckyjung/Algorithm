#include <bits/stdc++.h>
using namespace std;
//2493 탑
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;
	vector<pair<int, int>> vec;
	//타워 스택 <타워 인덱스, 타워 높이> 를 저장할 스택.

	//vector < map<int, int>> vec2;	어차피 map안에 쌓이는건데..
	//즉 vector를 사용할이유 X
	//map<int,int> m 의 경우는, 인덱스로 접근할때 사용하는경우.

	//m[index] = hegiht; 이런식으로하면, 트리 탐색하는데 시간이 걸림.
	//여기서는 스택을 이용해야 시간내 풀이 가능.


	for (int i = 1; i <= n; ++i) {
		int tower;
		cin >> tower;

		while (!vec.empty()) {	//타워스택이 존재하는경우 순회함.

			if (vec.back().second > tower) {
			//가장 가까히 있는 타워의 높이가 새로운 타워보다 높을경우.
			//if (vec.rbegin()->second > tower) { 위와 같음.
				cout << vec.back().first << " ";
				//해당 타워의 인덱스를 출력.
				vec.push_back({ i, tower });
				//그리고 새 타워를 타워 스택에 넣는다.
				break;
			}
			else {
				//새 타워보다 작은 기존의 타워들은 다 삭제
				vec.pop_back();
				//어차피 뒤에 새로운 타워들은 큰 타워에게 다 가로막힘.
			}
		}

		if (vec.empty()) {
			//타워 스택이 빈경우, 즉 앞에 타워가 없다면?
			cout << "0 ";
			//조건에 명시된대로 0을 출력
			vec.push_back({ i, tower });
			//그리고 새 타워를 타워스택에 넣는다.
		}
	}

	return 0;
}