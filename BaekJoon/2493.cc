#include <bits/stdc++.h>
using namespace std;
//2493 탑
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> tower;

	int num;
	cin >> num;
	while (num--) {
		int n;
		cin >> n;
		tower.push_back(n);
	}

	int len = tower.size() - 1;

	vector<int> ans;

	for (int i = len; i >= 0; --i) {

		//첫번째 탑은 어차피 만나는 탑이 없음.
		if (i == 0) {
			ans.push_back(0);
			break;
		}

		bool flag = true;
		for (int ii = i - 1; ii >= 0; --ii) {
			if (tower[i] < tower[ii]) {
				//ans.push_back(tower[ii]);
				ans.push_back(ii + 1);
				//인덱스에 관심이 있는거니 ii + 1값을 넣어줌.
				flag = false;
				break;
			}
		}
		//앞에서 더 큰게 없었으면, 그냥 0을 넣어줌.
		if (flag) ans.push_back(0);
	}

	//역방향으로 들어갔으니, 역방향으로 빼냄.
	while (!ans.empty()) {
		cout << ans.back() << " ";
		ans.pop_back();
	}


	return 0;
}