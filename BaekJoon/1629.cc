#include <bits/stdc++.h>
using namespace std;

//1629 곱셈.

#define ll long long

ll ans(ll a, ll n, ll m) {
	if (n == 0) return 1;
	//0승인경우 1리턴.
	ll val = ans(a, n / 2, m);
	//2^10이 들어왔을때 2^5를 만든다.
	val = val * val % m;
	//2^5 * 2^5 = 2^10 이다.
	if (n & 1)	return val* a% m;
	//만약 홀수 2^11 인경우, 2^5 * 2^5 한것에 2를 한번더 곱한다.
	return val;
	//아닌경우 받아온 결과값 리턴.
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll a, n, m;
	cin >> a >> n >> m;
	cout << ans(a, n, m);

	return 0;
}