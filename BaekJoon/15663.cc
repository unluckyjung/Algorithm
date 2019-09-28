#include<bits/stdc++.h>
using namespace std;

//아직 못풀었음.

//N과 M(9)
//https://www.acmicpc.net/problem/15663
int n, m;

vector<int> vec;
//들어오는 숫자를 보관해둘 vector를 만들었다.

vector<int> tmp;

int arr[10];
bool visit[10];

bool flag = true;

void func(int k) {
	if (k > m) {
		//if (flag) {
		//	flag = false;
		//	for (int i = 1; i <= m; ++i) {
		//		tmp.push_back(arr[i]);
		//		cout << arr[i] << " ";
		//	}
		//	cout << "\n";
		//}
		//else {
		//	for (int i = 1; i <= m; ++i) {
		//		if (arr[i] != tmp[i-1]) {
		//			//tmp에다가 arr의 모든값을 집어넣음.
		//			for (int ii = 1; ii <= m; ++ii) {
		//				cout << arr[ii] << " ";
		//				tmp[ii-1] = arr[ii];
		//			}
		//			cout << "\n";
		//			return;
		//		}
		//	}

		//}

		for (int i = 1; i <= m; ++i) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	int start = 1;

	for (int i = start; i <= n; ++i) {
		if (visit[i - 1] == true) continue;
		visit[i - 1] = true;
		arr[k] = vec[i - 1];
		func(k + 1);
		visit[i - 1] = false;
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