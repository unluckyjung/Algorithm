#include<bits/stdc++.h>
using namespace std;

//N과 M(8)
//https://www.acmicpc.net/problem/15657
int n, m;

vector<int> vec;
//들어오는 숫자를 보관해둘 vector를 만들었다.

int arr[10];
bool visit[10001];

void func(int k) {
	if (k > m) {
		for (int i = 1; i <= m; ++i) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	int start = 1;

	for (int i = start; i <= n; ++i) {
		//사용했던 숫자를 반복하여도 상관없다. visit가 필요없음.
		//대신 동일한 수열만 나오지 않으면된다.

		if (vec[i - 1] < arr[k - 1]) continue;
		//두번째로 나오는수는 앞의 수보다 작으면 안된다.

		arr[k] = vec[i - 1];
		//k번째의 수를 vec안의 숫자 중 아무거나 넣으면된다.
		func(k + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	//오름차순이라는 조건이 있으니, 정렬시킨다.
	func(1);

	return 0;
}