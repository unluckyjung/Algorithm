#include <bits/stdc++.h>
#include <regex>
using namespace std;

int work[3];
int go_home[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 0; i < 3; ++i) {
		cin >> work[0] >> work[1] >> work[2];
		cin >> go_home[0] >> go_home[1] >> go_home[2];

		int arr[3] = { go_home[0]-work[0], go_home[1] - work[1], go_home[2] - work[2] };
		
		for (int i = 2; i >= 0; --i) {
			if (arr[i] < 0) {
				arr[i - 1]--; arr[i] += 60;
			}
		}

		for (int i = 0; i < 3; ++i) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
