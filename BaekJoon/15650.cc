#include<bits/stdc++.h>
using namespace std;

//15650 N과 M (2)

int n, m;

int arr[10];
bool visit[10];	//방문했다는 표시를 남기는 visit
void func(int k) {
	if (k > m) {	//찾으려는 수가 범위 밖을 벗어나면, arr 담긴 모든 수를 출력한다.
		for (int i = 1; i <= m; ++i) cout << arr[i] << " ";
		cout << "\n"; return;
	}

	int start = 1;
	if (k > 1) {
		//오름차순이라는 조건이 있다.
		//찾는수가 2번째 이상의 수라면
		start = arr[k - 1];
		//찾는수의 시작을 앞의 수로 시작한다.
	}
	for (int i = start; i <= n; ++i) {
		if (visit[i] == true)continue;
		visit[i] = true;
		arr[k] = i;
		func(k + 1);
		visit[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	func(1);

	return 0;
}