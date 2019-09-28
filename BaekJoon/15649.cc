#include<bits/stdc++.h>
using namespace std;
//15649 N과 M (1)

int n, m;
//1부터 n까지의 숫자가 들어갈 수 있다.
//m개의 수가 출력된다.

int arr[100];	//숫자를 담을 배열!	최대 m개까지 채워진다.
bool visit[100];	//해당숫자가 방문했는지 기록하는 배열


void func(int k) {	
	//k번쨰 숫자를 찾는함수

	if (k > m) {	//m보다 더 많은 숫자를 담으려고 시도하면
		for (int i = 1; i <= m; ++i) cout << arr[i] << " ";
		//배열이 다 찻단 이야기므로 출력시킨다.
		cout << "\n";
		return;
	}
	
	for (int i = 1; i <= n; ++i) {
		//1부터 n까지를 순회한다.
		if (visit[i] == true) continue;	//해당숫자가 방문되었다면 continue

		visit[i] = true;	//방문 표시를 한다.
		arr[k] = i;	//배열에다가 해당 숫자를 넣는다.
		func(k + 1);	//다음숫자를 찾으러 떠난다.
		visit[i] = false;	//방문 표시한것을 해제한다.
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	func(1);	//1번째 숫자를 찾으러 간다.

	return 0;
}