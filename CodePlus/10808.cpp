#include<bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;
	//int size = s.size();

	// for (int i = 'a'; i <= 'z'; ++i) {
	// 	int count = 0;
	// 	for (int j = 0; j < size; ++j) {
	// 		if (i == s[j])
	// 			count++;
	// 	}
	// 	printf("%d ", count);
	// }

	for (int i = 'a'; i <= 'z'; ++i) {
		cout << count(s.begin(), s.end(), i) << ' ';
		//count() 숫자를센다. 범위1, 범위2, 찾는숫자.
		//s.begin()은 s의 첫번째 것.
	}
	printf("\n");


	return 0;
}