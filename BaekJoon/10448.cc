#include <bits/stdc++.h>
using namespace std;
//백준 10448 유레카이론
//https://www.acmicpc.net/problem/10448

int arr[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i <= 1000; ++i) {
		arr[i] = i * (i + 1) / 2;
	}

	int cnt; cin >> cnt;
	while (cnt--) {
		bool flag = false;
		int num; cin >> num;
		for (int i = 1; i <= num; ++i) {
			for (int ii = 1; ii <= num; ++ii) {
				for (int iii = 1; iii <= num; ++iii) {
					if (arr[i] + arr[ii] + arr[iii] == num) {
						flag = true; break;
						//만약 삼각수의 합으로 포현된다면 for문을 빠져나감.
					}
				}
				if (flag)break;
			}
			if (flag)break;
		}
		if (flag) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}