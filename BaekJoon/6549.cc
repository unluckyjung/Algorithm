#include<bits/stdc++.h>
#define ll long long
#define MAX 100001
using namespace std;

stack<pair<ll,ll> > s;	//index, height;
ll answer;

int n;
ll h;

void empty_check(int n) {
	while (!s.empty()) {
		ll top_i = s.top().first;
		ll top_h = s.top().second;
		s.pop();
		if(s.empty())	answer = max(answer, n * top_h);
		else {
			ll before_top_i = s.top().first;
			//answer = max(answer, (((n - top_i) + (top_i - before_top_i-1)))* top_h);
			answer = max(answer, (n - before_top_i - 1) * top_h);
		}
	}
}

void top_check(int i) {
	cin >> h;
	while (!s.empty()) {
		ll top_i = s.top().first;
		ll top_h = s.top().second;

		if (h >= top_h) {
			s.push({ i,h });
			return;
		}
		else {
			s.pop();

			if (s.empty())	answer = max(answer, i * top_h);
			else {
			ll before_top_i = s.top().first;
			//answer = max(answer, (((i-top_i) + (top_i - before_top_i -1))* top_h));
			answer = max(answer, (i - before_top_i - 1)*top_h);	//위와 같음.
			}
		}
	}
	s.push({ i,h });
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt", "r", stdin);
	while (1) {
		answer = 0;
		cin >> n;
		if (n == 0)break;

		for (int i = 0; i < n; ++i) {
			top_check(i);
		}
		empty_check(n);
		cout << answer << "\n";
	}

	return 0;
}