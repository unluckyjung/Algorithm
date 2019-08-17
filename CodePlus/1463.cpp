#include <bits/stdc++.h>
using namespace std;
int dp1[1000001]; 
int dp2[1000001];


int Make_one1(int n) {  //Top down
	if (n == 1) {
		return 0;
	}
	if (dp1[n] > 0) {
		return dp1[n];
	}
	dp1[n] = Make_one1(n - 1) + 1;

	if (n % 2 == 0) {
		int temp = Make_one1(n / 2) + 1;
		if (temp < dp1[n]) {
			dp1[n] = temp;
		}
	}

	if (n % 3 == 0) {
		int temp = Make_one1(n / 3) + 1;
		if (temp < dp1[n]) {
			dp1[n] = temp;
		}
	}
	return dp1[n];
}


int Make_one2(int n) {  //Bomttom up
	dp2[1] = 0;
	for (int i = 2; i <= n; ++i) {
		dp2[i] = dp2[i - 1] + 1;
		if (i % 2 == 0 && dp2[i] > dp2[i / 2] + 1) {
			dp2[i] = dp2[i / 2] + 1;
		}
		if (i % 3 == 0 && dp2[i] > dp2[i / 3] + 1)
			dp2[i] = dp2[i/3] + 1;
	}
	return dp2[n];
}

int main() {
	cout << Make_one2(6);
	return 0;
}

