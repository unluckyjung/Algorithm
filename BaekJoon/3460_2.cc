#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	while(count--){
		int num;
		cin >> num;

		int index = 0;
		while (num) {
			if (num % 2 == 1) {
				if (num / 2 != 0) cout << index << " ";
				else cout << index;
			}
			num /= 2;
			index++;
		}
		cout << "\n";
	}

	return 0;
}