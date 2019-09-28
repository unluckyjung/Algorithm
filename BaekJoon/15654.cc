#include<bits/stdc++.h>
using namespace std;

//15654 N과 M (5)
//https://www.acmicpc.net/problem/15654
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
		if (visit[vec[i-1]]) continue;
		//시작지점이 1이라서, vec[1]부터 접근하면 두번째 원수부터 참조하므로
		//vec[i-1] 형태로 접근한다.
		//벡터에 담긴 숫자가 사용되었다면, 건너 뛴다.
		visit[vec[i-1]] = true;
		arr[k] = vec[i-1];
		func(k + 1);
		visit[vec[i-1]] = false;
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