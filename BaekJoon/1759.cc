#include<bits/stdc++.h>

//백준 1759 암호만들기
//https://www.acmicpc.net/problem/1759

using namespace std;

char ans[20];	//정답을 보관할 배열
string arr;


int n, m;

int con1;
int con2;

void func(int k) {

	if (k > n and con1 >= 1 and con2 >=2) {
		for (int i = 1; i <= n; ++i)	cout << ans[i];
		cout << "\n";	return;
	}


	int start = 1;

	if (k <= n) {
		//만약 이 조건을 주지않는다면,
		//k가 4일때 모음, 자음수를 만족하지 못하면
		//k가 5가 되어서 이 루프문을 또 돌게된다.
		//base conditon의 조건을 잘 생각하자.
		for (int i = start; i <= m; ++i) {

			if (arr[i - 1] <= ans[k - 1])continue;
			//배열을 다 탐색하면서, 
			//만약 뒤에 나오는 값의 아스키 코드값이 앞보다 작거나 같으면 건너뛴다.
			//arr[i-1]인 경우는 arr은 0부터 채워져 있기때문.
			//ans[0]은 어차피 0이라서, 문자 아스키 코드보다 항상 작다.

			ans[k] = arr[i - 1];

			//모음이나 자음의 등장 횟수를 기록한다.
			if (ans[k] == 'a' or ans[k] == 'e' or ans[k] == 'i' or ans[k] == 'o' or ans[k] == 'u') con1++;
			else con2++;

			func(k + 1);

			if (ans[k] == 'a' or ans[k] == 'e' or ans[k] == 'i' or ans[k] == 'o' or ans[k] == 'u') con1--;
			else con2--;
		}
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		char c;
		cin >> c;
		arr.push_back(c);
	}

	sort(arr.begin(), arr.end());

	func(1);

	return 0;
}