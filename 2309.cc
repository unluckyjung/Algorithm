#include <bits/stdc++.h>
using namespace std;

int arr[9];
bool visit[9];

void func(int sum, int count) {
	if (count > 7) return;
	// 이전에 잘못 쓴답
	// sum + arr[i] == 100

	// 더해지고 넘어온수 ! 그리고 count는 몇번 더했는지! 
	if (sum == 100 and count == 7) {
		for (int i = 0; i < 9; ++i) {
			if (!visit[i])continue;
			cout << arr[i] << "\n";
		}
		exit(0);	//답이었다면, 바로 프로그램 종료
	}

	for (int i = 0; i < 9; ++i) {	//배열안의 모든 숫자를 탐색.
		if (!visit[i]) {	//사용하지 않은 수 였다면?
			visit[i] = true;	//해당 인덱스에 방문했다는 표시를 해둠.
			int r_sum = sum + arr[i];	//r_sum에 이전의 합 + 지금 방문하는 값
			int r_count = count+1;	//한개를 더했으니 count의 수도 늘어남.
			func(r_sum, r_count);	//바뀐 값으로 진행
			visit[i] = false;	//답이 아니었다면, 방문한 표시를 삭제함.
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; ++i) {
		int num;
		cin >> num;
		arr[i] = num;
	}

	sort(arr, arr + 9);
	func(0, 0);

	return 0;
}