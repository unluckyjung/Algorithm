#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	int yong = 0;	//30초에
	int min = 0;	//60초에

	bool flag = true;

	while (cnt--) {
		int n;
		cin >> n;


		if (n == 0) continue;
		flag = false;
		int n2 = n;

		int ycnt = 1;
		while (1) {
			if (n - 30 >= 0) {
				n -= 30;
				ycnt++;
			}
			else break;
		}
		yong += 10 * ycnt;


		int mcnt = 1;
		while (1) {
			if (n2 - 60 >= 0) {
				n2 -= 60;
				mcnt++;
			}
			else break;
		}
		min += 15 * mcnt;

	}

	if (flag) {
		cout << "Y M " << 0;
		return 0;
	}

	if (yong == min) {
		cout << "Y M " << yong;
		return 0;
	}
	else if (yong < min) {
		cout << "Y " << yong;
		return 0;
	}
	else {
		cout << "M " << min;
		return 0;
	}

	return 0;
}