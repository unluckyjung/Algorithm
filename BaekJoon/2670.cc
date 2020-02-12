#include <bits/stdc++.h>
#define MAX 10001
using namespace std;
int n;
double arr[MAX], dp[MAX], answer;

#if 01
void solve() {
	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i], dp[i] * dp[i - 1]);
		answer = max(answer, dp[i]);
	}
	printf("%.3f\n", answer);
}

void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &arr[i]);
		dp[i] = arr[i];
	}
}

#else
void solve() {
	double tmp;
	for(int i = 0 ; i<n; ++i){
		tmp = 1.0;
		for (int ii = i; ii < n; ++ii) {
			if (arr[ii] == 0)break;
			tmp *= arr[ii];
			answer = max(answer, tmp);
		}
	}
	printf("%.3f", answer);
}

void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &arr[i]);
	}
}


#endif

int main()
{
    freopen("input.txt", "r", stdin);
	input();
	solve();

	return 0;
}