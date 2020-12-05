#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mooLen[100];

char findMooChar(ll order) {
	if (order <= mooLen[0]) {
		if (order == 1) return 'm';
		return 'o';
	}
	int mooCount = 1;
	while (mooLen[mooCount] <= order) {
		mooCount++;
	}

	ll midRange = mooLen[mooCount - 1] + 1 + mooCount + 2;

	if (order <= midRange) {
		//if (midRange - mooLen[mooCount-1] == order) return 'm';
		if (order - mooLen[mooCount - 1] == 1) return 'm';
		return 'o';
	}
	return findMooChar(order - midRange);
	// 실수한 부분
	// 분할된 곳에서의 새 위치를 찾아야 넘겨야 되는데, 남은 "길이"를 넘겼다.
}

void mooArrasySet() {
	mooLen[0] = 3;
	int mooCount = 0;
	while (mooLen[mooCount] <= 1e9) {
		mooCount++;
		mooLen[mooCount] = mooLen[mooCount - 1] * 2 + 1 + mooCount + 2;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	mooArrasySet();
	ll n;
	cin >> n;
	cout << findMooChar(n);

	return 0;
}