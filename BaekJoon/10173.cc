#include<bits/stdc++.h>
using namespace std;
//백준 10713
//https://www.acmicpc.net/problem/10173

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	while (getline(cin, str)) {
		if (str == "EOI")	return 0;
		for(int i = 0 ; i<(int)str.size(); ++i) str[i] = toupper(str[i]);
		//전부다 대문자로 바꾸어버린다.

		if (str.find("NEMO") != -1) cout << "Found\n";
		else cout << "Missing\n";
	}

	return 0;
}