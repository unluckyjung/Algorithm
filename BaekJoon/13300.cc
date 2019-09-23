#include <bits/stdc++.h>
using namespace std;

int arr[2][6];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<vector<int>> man(7);	//학년별 6개의 방을 만듬. (0제외)
	vector<vector<int>> woman(7);

	int N, K;

	cin >> N >> K;
	int S, Y;
	while (N--) {
		cin >> S >> Y;
		if (S == 0) woman[Y].push_back(1);
		else man[Y].push_back(1);
	}

	int sum = 0;

	for (int i = 1; i <= 6; ++i) {
		sum += man[i].size() / K;
		if (man[i].size() % K != 0) sum++;

		sum += woman[i].size() / K;
		if (woman[i].size() % K != 0) sum++;
	}

	cout << sum;

	return 0;
}