#include <bits/stdc++.h>
using namespace std;
string pipe;

int solve() {
	int sum = 0, pipe_num = 0;
	int pipe_len = pipe.size();
	for (int i = 0; i < pipe_len; ++i) {
		if (pipe[i] == '(') pipe_num++;
		else {
			if (pipe[i - 1] == '(') {
				pipe_num--;
				sum += pipe_num;
			}
			else {
                pipe_num--;
				sum++;
			}
		}
	}
	return sum;
}

void input() {
	cin >> pipe;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    freopen("input.txt", "r", stdin);

	input();
	cout << solve();

	return 0;
}