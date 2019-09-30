#include<bits/stdc++.h>
using namespace std;
//백준 2857 FBI
//https://www.acmicpc.net/problem/2857

vector<string> FBI;

vector<int> vec;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 5;
	while (num--) {
		string str;
		cin >> str;
		FBI.push_back(str);
	}

	for (int i = 0; i < 5; ++i) {
		if (FBI[i].find("FBI") != -1) vec.push_back(i + 1);
	}

	sort(vec.begin(), vec.end());
	if (vec.empty()) {
		cout << "HE GOT AWAY!";	return 0;
	}
	else {
		for (auto i : vec)	cout << i << " ";
	}

	return 0;
}