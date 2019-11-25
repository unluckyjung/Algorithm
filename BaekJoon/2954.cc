#include<bits/stdc++.h>
#include<regex>
using namespace std;

int main() {
	string str;
	//char encypt[5] = { 'a', 'e', 'i', 'o','u' };
	getline(cin, str);

	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			cout << str[i]; i += 2;
		}
		else
		{
			cout << str[i];
		}
	}
	return 0;
}