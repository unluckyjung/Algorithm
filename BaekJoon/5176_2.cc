#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	while (cnt--) {
		int stu;
		int chair;
		int count = 0;
		vector<int> vec;
		int arr[501] = { 0 };

		cin >> stu >> chair;
		//이방법은 chair 변수를 아예 사용하지 않음.

		while (stu--) {
			int want;
			cin >> want;
			if (arr[want] == 0) arr[want] = 1;	//원하는자리에 누가 최초로 접근하면 해당 값을 1로 바꿈.
			else {
				count++;	//누가 이미 찜한 자리에 접근시 count ++;
			}
		}
		cout << count << "\n";
	}
	return 0;
}