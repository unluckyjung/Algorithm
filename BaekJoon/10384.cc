#include<bits/stdc++.h>

using namespace std;

int t;

int pangram[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	cin.ignore();
	for(int i = 1; i<=t; ++i) {
		string str;
		getline(cin, str);

		memset(pangram, 0, sizeof(pangram));

		for (char c : str) {
			if (isalpha(c)) {
				int index = (tolower(c) - 'a');
				pangram[index]++;
			}
		}

		int MIN = *min_element(pangram, pangram + 26);
		
		if (MIN == 0) {
			cout << "Case " << i << ": Not a pangram\n";
		}
		else if (MIN == 1) {
			cout << "Case " << i << ": Pangram!\n";
		}
		else if (MIN == 2) {
			cout << "Case " << i << ": Double pangram!!\n";
		}
		else if (MIN == 3) {
			cout << "Case " << i << ": Triple pangram!!!\n";
		}
	}
	return 0;
}