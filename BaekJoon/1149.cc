#if 01

#include <bits/stdc++.h>
using namespace std;

int dp[1001][4];
int color[1001][4];
int N;
int answer = INT_MAX;

void make_dp(int n, int m) {
    dp[n][m] = INT_MAX;

    for (int k = 1; k <= 3; ++k) {
        if (k == m)continue;
        dp[n][m] = min(dp[n][m], dp[n - 1][k] + color[n][m]);
    }
}

void solve() {
    for (int i = 2; i <= N; ++i) {
        for (int ii = 1; ii <= 3; ++ii) {
            make_dp(i, ii);
        }
    }
    cout << min({ dp[N][1], dp[N][2], dp[N][3] }) << "\n";
}

void init(int house) {
    for (int i = 1; i <= 3; ++i) {
        cin >> color[house][i];
    }
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        init(i);
    }
    dp[1][1] = color[1][1];
    dp[1][2] = color[1][2];
    dp[1][3] = color[1][3];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}


#else


#include <bits/stdc++.h>
using namespace std;
//백준 RGB거리 1149
//https://www.acmicpc.net/problem/1149

int color[3][1002];
int price[3][1002];

int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> color[0][i];
		cin >> color[1][i];
		cin >> color[2][i];
		//빨강(0), 파랑(1), 초록(2) 순으로 입력받는다.
		//뒤의 i는 케이스의 수.
	}

	price[0][0] = color[0][0];
	//0번째 케이스에서
	//0번째 빨간색에칠할때 최소값은 color에 들어간 첫번쨰 값
	price[1][0] = color[1][0];
	price[2][0] = color[2][0];

	for (int i = 1; i < n; ++i) {
		price[0][i] = min(price[1][i - 1], price[2][i - 1]) + color[0][i];
		//빨간색으로 i번쨰 집을 칠한다.
		//이전의 집이 파란색일때, 혹은 이전의 집이 초록색일때 + i번째 케이스의 빨간색으로 칠하는경우.

		//각각의 케이스별로 연산.
		price[1][i] = min(price[0][i - 1], price[2][i - 1]) + color[1][i];
		price[2][i] = min(price[0][i - 1], price[1][i - 1]) + color[2][i];
	}

	cout << min(min(price[0][n - 1], price[1][n - 1]), price[2][n - 1]);


	return 0;
}


#endif