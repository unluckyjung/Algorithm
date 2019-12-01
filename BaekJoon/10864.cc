#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	vector<vector<bool>> vec(n, vector<bool>(n, false));

	while (m--) {
		int h1, h2;
		cin >> h1 >> h2;

		vec[h1-1][h2-1] = true;
		vec[h2-1][h1-1] = true;
	}

	for (int i = 0; i < vec.size(); ++i) {
		int friends = 0;
		for (int ii = 0; ii < vec[i].size(); ++ii) {
			if (vec[i][ii] == true)	friends++;
		}
		cout << friends << "\n";
	}
	return 0;
}