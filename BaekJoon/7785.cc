#include<bits/stdc++.h>

using namespace std;

long long n;
map<string, long long> m;
int main() {
	cin >> n;
	while (n--) {
		string name, behavior;
		cin >> name >> behavior;
		if (behavior == "enter")
			m[name]++;
		else
			m[name]--;
	}

	for (auto it = m.rbegin(); it != m.rend(); ++it) {
		if (it->second == 1) cout << it->first << '\n';
	}
	return 0;
}