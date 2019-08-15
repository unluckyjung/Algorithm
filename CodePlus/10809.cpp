#include<bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;


	//int size = s.size();
	//for (int i = 'a'; i <= 'z'; ++i) {
	//	bool flag = false;

	//	for (int j = 0; j < s.size(); ++j) {
	//		if (s[j] == i) {
	//			printf("%d ", j);
	//			flag = true;
	//			break;
	//		}
	//	}
	//	if (flag == false) {
	//		printf("-1 ");
	//	}
	//}
	
	//for (int i = 'a'; i <= 'z'; i++) {
	//	auto find_c = find(s.begin(), s.end(), i);	//find는 못찾으면 s.end()를 리턴
	//	if (find_c == s.end()) {	
	//		printf("-1 ");
	//	}
	//	else
	//		printf("%d ", find_c - s.begin());	//찾은위치 - 처음위치를 존재했던 위치 확인가능.
	//}

	for (int i = 'a'; i <= 'z'; i++) {
		printf("%d ", s.find(i));	//이렇게 쉽게도가능.
	}

	printf("\n");
	return 0;
}