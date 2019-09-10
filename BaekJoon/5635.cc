#include <bits/stdc++.h>
using namespace std;

int MAX = 0;
int MIN = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	string name;
	int day, month, year;

	vector<string> n;
	vector<int> d, m, y;
	while (count--)
	{
		cin >> name >> day >> month >> year;
		n.push_back(name);
		d.push_back(day);
		m.push_back(month);
		y.push_back(year);
	}

	for (int i = 0; i < (int)n.size(); ++i)
	{
		if (y[i] > y[MAX]) MAX = i;
		else if (y[i] == y[MAX]) {
			if (m[i] > m[MAX]) MAX = i;
			else if (m[i] == m[MAX]) {
				if (d[i] > d[MAX]) MAX = i;
			}
		}

		if (y[i] < y[MIN]) MIN = i;
		else if (y[i] == y[MIN]) {
			if (m[i] < m[MIN]) MIN = i;
			else if (m[i] == m[MIN]) {
				if (d[i] < d[MIN]) MIN = i;
			}
		}
	}

	cout << n[MAX] << "\n";
	cout << n[MIN];

	return 0;
}