#include<bits/stdc++.h>
using namespace std;

//N과 M (6)
//https://www.acmicpc.net/problem/15655
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
	//이문제는 start 기점을 건드는게 아니다.

	for (int i = start; i <= n; ++i) {
		if (vec[i-1] <= arr[k - 1]) continue;
		//오름차순으로 중복되지 않아야하며
		//** 뒤의 숫자가 앞의 수보다 항상 커야한다. **
		//n은 항상 1이상의 수이기 때문에, vec의 수가 arr[0]보다 작은 경우는없다.

		//vec안에 들어가있는 수가 arr첫번째 수보다 크지 않다면 넘어간다.
		arr[k] = vec[i - 1];
		//k번째 수를 vec안에 있는 수로 설정한다.
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