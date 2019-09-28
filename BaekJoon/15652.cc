#include<bits/stdc++.h>
using namespace std;
//15652 N과 M (4)

int n, m;
//1부터 n까지의 숫자가 들어갈 수 있다.
//m개의 수가 출력된다.

int arr[100];	//숫자를 담을 배열!	최대 m개까지 채워진다.


void func(int k) {	
	//k번쨰 숫자를 찾는함수

	if (k > m) {	//m보다 더 많은 숫자를 담으려고 시도하면
		for (int i = 1; i <= m; ++i) cout << arr[i] << " ";
		//배열이 다 찻단 이야기므로 출력시킨다.
		cout << "\n";
		return;
	}
	
	int start = 1;
	if (k > 1)	start = arr[k-1];
	//1,2가 차 있고 
	//3번째 수를 찾는다고 가정해보자. 3-1 하여 arr[2]에 들어간 수인 2부터 순회한다.
	//앞의 수보다 작아지면 안되기 때문!
	for (int i = start; i <= n; ++i) {
		//1부터 n까지를 순회한다.
		arr[k] = i;	//배열에다가 해당 숫자를 넣는다.
		func(k + 1);	//다음숫자를 찾으러 떠난다.
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	func(1);	//1번째 숫자를 찾으러 간다.

	return 0;
}