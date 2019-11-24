#include<bits/stdc++.h>
#include<regex>
using namespace std;

int T;
int leg, chicken;
int main() {
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> leg >> chicken;
		int chick = chicken * 2 - leg;
		cout << chick << ' ' << chicken - chick << '\n';
	}

	return 0;
}