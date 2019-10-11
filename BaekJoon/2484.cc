#include<bits/stdc++.h>
using namespace std;
//백준 2484 주사위 네개
//https://www.acmicpc.net/problem/2484

int arr[7];
int MAX = INT_MIN;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//4개 50000 + 같은눈 * 5000;
	//3개 10000 + 3개 나온눈 * 1000
	//2개 두쌍 2000 + (다른 두개눈 * 500 * 2)
	//2개 한쌍 1000 + 같은눈 * 1000
	//모두 다른눈, 가장 큰눈 * 100

	int cnt; cin >> cnt;
	while (cnt--) {
		memset(arr, 0, sizeof(arr));

		int tryy = 4;
		while (tryy--) {
			int num; cin >> num;
			arr[num]++;
		}

		int result = 0;
		int twoflag = 0;

		for (int i = 1; i <= 6; ++i) {
			if (arr[i] == 4) {
				result = 50000 + i * 5000;
				break;
			}
			else if (arr[i] == 3) {
				result = 10000 + i * 1000;
				break;
			}
			else if (arr[i] == 2) {
				if (twoflag == 0) {
					twoflag = i;
					result = 1000 + i * 100;
				}
				else {
					result = 2000 + (twoflag * 500) + (i * 500);
					break;
				}
			}
		}

		if (result == 0) {
			for (int i = 6; i >= 1; --i) {
				if (arr[i] == 1) {
					result = i * 100; break;
				}
			}
		}
		MAX = max(MAX, result);

	}
	cout << MAX;
	return 0;
}