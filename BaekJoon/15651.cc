#include<bits/stdc++.h>
using namespace std;

//15651 N과 M (3)
//https://www.acmicpc.net/problem/15651
int n, m;

int arr[10];
void func(int k) {
	if (k > m) {	//찾으려는 수가 범위 밖을 벗어나면, arr 담긴 모든 수를 출력한다.
		for (int i = 1; i <= m; ++i) cout << arr[i] << " ";
		cout << "\n"; return;
	}

	int start = 1;

	//중복되어도 상관없으니 start 에 변화를 줄 필요가없다.
	//당연히 visit도 사용할 필요가 없다.
	for (int i = start; i <= n; ++i) {
		arr[k] = i;
		func(k + 1);
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