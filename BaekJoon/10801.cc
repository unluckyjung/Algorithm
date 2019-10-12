#include<bits/stdc++.h>
using namespace std;
//백준 10801 카드게임
//https://www.acmicpc.net/problem/10801

int A[11];
int B[11];
int p1, p2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; ++i) cin >> A[i];
	for (int i = 0; i < 10; ++i) cin >> B[i];

	for (int i = 0; i < 10; ++i) {
		if (A[i] == B[i])continue;
		else if (A[i] > B[i]) p1++;
		else p2++;
	}
	

	if (p1 == p2) cout << 'D';
	else if (p1 > p2) cout << 'A';
	else cout << 'B';

	return 0;
}