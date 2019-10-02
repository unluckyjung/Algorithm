#include <bits/stdc++.h>
using namespace std;
//백준 9466 텀프로젝트
//https://www.acmicpc.net/problem/9466


int want[100002];
bool visit[100002];
bool team[100002];

int n;
int cnt;

void DFS(int k) {
	visit[k] = true;
	//이전 사람을 방문 표시.

	int cur = want[k];
	//현재 사람은 이전의 사람이 원하는 사람이 된다.
	if (visit[cur] == false)	DFS(cur);
	//현재 사람이 지목된적이 없다면, 다시 DFS를 돌린다. 

	else if (team[cur] == false) {
		//현재사람이 지목된적이 있는사람이지만, 또 지목된경우 
		//팀을 이룸에 성공
		for (int i = cur; ; i = want[i]) {
			cnt++;
			if (i == k) break;
		}
		//현재 사람이 가르키는팀원 arr[cur],
		//그리고 arr[cur]가 가르키는 팀원 arr[arr[cur]]... 전부 샌다.
		//하다가 자기 자신까지 온경우 종료.
	}
	team[k] = true;
	//이전에 team[cur]로해서 무한루프돔.
	//이 사람은 다시는 참조하지 않을것이다.
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		memset(visit, false, sizeof(visit));
		memset(team, false, sizeof(team));

		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> want[i];
		//각자 원하는 사람을 적어둔다.
		cnt = 0;
		//cnt는 팀을 이루고 있는 사람들의 숫자.

		for (int i = 1; i <= n; ++i) {
			if (visit[i] == false)	DFS(i);
			//지목 받지 않은 사람이면, 그 사람으로 DFS를 돈다.
		}
		cout << n - cnt << "\n";
	}

	return 0;
}