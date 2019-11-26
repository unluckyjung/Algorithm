#include<bits/stdc++.h>
#include<regex>
using namespace std;

int main() {
	cin.tie(NULL);

	int cnt = 1;
	while (1) {
		string str1, str2;
		cin >> str1 >> str2;
		if (str1 == "END")	break;
		cout << "Case " << cnt++ << ": ";


		if (str1.size() != str2.size()) {
			cout << "different\n";
			continue;
		}

		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());

		bool flag = false;
		for (int i = 0; i < (int)str1.size(); ++i) {
			if (str1[i] != str2[i]) {
				flag = true; break;
			}
		}
		if (flag)	cout << "different\n";
		else cout << "same\n";
	}

	return 0;
}