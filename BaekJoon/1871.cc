#include<bits/stdc++.h>
using namespace std;
//백준 좋은 자동차 번호판 1871
//https://www.acmicpc.net/problem/1871


char str[3];
int n, num;


int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);


	cin >> n;
	while (n--) {
		int sum1 = 0, sum2 = 0;
		getchar();
		scanf("%[^-]-%d", str, &num);
		sum1 += (str[0] - 'A') * 26 * 26 + (str[1] - 'A') * 26 + (str[2] - 'A');
		if (abs(num - sum1) <= 100) cout << "nice\n";
		else cout << "not nice\n";
	}

	return 0;
}