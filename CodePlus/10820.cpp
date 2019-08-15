#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;

	while (getline(cin, s)) {	//공백도 같이 입력받는다.	getline(cin, string)
		//EOF 입력을 생각하라.
		int a = 0, A = 0, n = 0, blank = 0;

		for (int i = 'a'; i <= 'z'; ++i) {
			a += count(s.begin(), s.end(), i);
		}
		for (int i = 'A'; i <= 'Z'; ++i) {
			A += count(s.begin(), s.end(), i);
		}
		for (int i = '0'; i <= '9'; ++i) {
			n += count(s.begin(), s.end(), i);
		}
		blank = count(s.begin(), s.end(), ' ');

		printf("%d %d %d %d\n", a, A, n, blank);
	}


	//while (getline(cin, s)) {
	//	int lower = 0;
	//	int upper = 0;
	//	int number = 0;
	//	int space = 0;
	//	for (char x : s) {
	//		if (x >= 'a' && x <= 'z') {
	//			lower += 1;
	//		}
	//		else if (x >= 'A' && x <= 'Z') {
	//			upper += 1;
	//		}
	//		else if (x >= '0' && x <= '9') {
	//			number += 1;
	//		}
	//		else if (x == ' ') {
	//			space += 1;
	//		}
	//	}
	//	cout << lower << ' ' << upper << ' ';
	//	cout << number << ' ' << space << '\n';
	//}
	return 0;
}