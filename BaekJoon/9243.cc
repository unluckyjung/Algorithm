#include<bits/stdc++.h>
using namespace std;
//백준 파일 완전삭제 9243
//https://www.acmicpc.net/problem/9243


string file;
string check;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> file;
	if (n & 1) {
		for (int i = 0; i < (int)file.size(); ++i) {
			if (file[i] == '0') file[i] = '1';
			else file[i] = '0';
		}
	}

	cin >> check;
	if (file == check)	cout << "Deletion succeeded";
	else cout << "Deletion failed";


	return 0;
}