#include <bits/stdc++.h>
using namespace std;

vector<int> coin;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num, result;
	int coin_num = 0;

	cin >> num >> result;

	for (int i = 0; i < num; ++i) {
		int num;
		cin >> num;
		coin.push_back(num);
	}

	for (int i = num - 1; i >= 0; --i) 
	{
		int tmp = result / coin[i];	// 결과값 / 코인의 가치
		coin_num += tmp;	//tmp는 코인의 갯수.
		result = result - tmp * coin[i];	//결과값에 남은 액수를 저장.
	}
	cout << coin_num;
	return 0;
}