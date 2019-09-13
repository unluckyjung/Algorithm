#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
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
			if (num % 2 == 1) arr[index]++;
			num = num / 2;
			index++;
		}
		for (int i = 0; i < 1000001; ++i) {
			if (arr[i] == 1) cout << i << " ";
		}
		cout << "\n";
		memset(arr, 0, 1000001);
	}


	return 0;
}