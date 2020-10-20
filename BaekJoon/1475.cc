#include <bits/stdc++.h>
using namespace std;


#if 00
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, int> m;

	string str;
	cin >> str;

	for (int i = 0; i < (int)str.size(); ++i) {
		m[str[i] - '0']++;
	}

	if ((m[6] + m[9]) % 2 != 0) {	//66666 같이 5개인 경우, +1 해줘야함
		m[6] = (m[6] + m[9]) / 2 + 1;
		m[9] = m[6];
	}
	else {
		m[6] = (m[6] + m[9]) / 2;
		m[9] = m[6];
	}

	int MAX = -1;
	for (int i = 0; i <= 9; ++i) {
		MAX = max(MAX, m[i]);
	}

	cout << MAX;
	return 0;
}

#else

#include <bits/stdc++.h>
#define MAX 10
using namespace std;

int roomNum[MAX];

void solve() {
    string num; cin >> num;
    for (const char &ch : num) {
        if (ch == '9') roomNum[6]++;
        else roomNum[ch - '0']++;
    }

    if (roomNum[6] % 2 == 0) roomNum[6] /= 2;
    else roomNum[6] = roomNum[6] / 2 + 1;
    cout << *max_element(roomNum, roomNum + MAX) << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    solve();

    return 0;
}

#endif