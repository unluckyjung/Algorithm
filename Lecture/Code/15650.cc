#include <bits/stdc++.h>
using namespace std;

int a[10];

void go(int index, int start, int n, int m) {	//index 번째를 채우려고한다.
	if (index == m) {	//채우려는 수가 마지막 위치라면?
		for (int i = 0; i < m; ++i) {	//출력 시작
			cout << a[i];
			if (i != m - 1) cout << " ";	//뒤에 출력할게 남아있다면, 공백 출력
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = start; i <= n; ++i) {
			a[index] = i;
			go(index + 1, i + 1, n, m);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);


	return 0;
}