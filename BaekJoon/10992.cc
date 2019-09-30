#include<bits/stdc++.h>
using namespace std;
//백준 10992 별찍기 - 17

int n;

void star(int i) {
	while (i--)
		cout << "*";
}

void blank(int i) {
	while (i--)
		cout << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		//for (int blank = 1; blank <= n - i; ++blank) cout << " ";
		blank(n-i);
		if (i == 1 or i == n) {
			//for (int star = 1; star <= i * 2 - 1; ++star) cout << "*";
			star(i*2-1);
		}
		else {
			cout << "*";
			//for (int blank = 1; blank <= (i - 1) * 2 - 1; ++blank) cout << " ";
			blank(i * 2 - 3);
			//중간의 공백을 출력하는 부분
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}