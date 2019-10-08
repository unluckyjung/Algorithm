#include<bits/stdc++.h>
using namespace std;
//백준 JOI와 IOI 5586
//https://www.acmicpc.net/problem/5586

int JOI_cnt;
int IOI_cnt;
string str;
void IOI_count(int i) {
	while (1) {

		i = str.find("IOI", i);
		//find의 뒤 숫자는 이 인덱스부터 탐색하겠다는 의미이다.
		if (i == -1)break;
		//못찾으면 -1 반환.

		i++;
		IOI_cnt++;
		//찾을경우, 한칸뒤부터 탐색하기 위해 i++
	}
}

void JOI_count(int i) {
	while (1) {

		i = str.find("JOI", i);
		if (i == -1)break;
		i++;
		JOI_cnt++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	IOI_count(0);
	JOI_count(0);

	cout << JOI_cnt << "\n" << IOI_cnt;
	return 0;
}