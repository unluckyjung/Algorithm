#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int size = s.size();
	for (int i = 0; i < size; ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = s[i] + 13;
			if (s[i] > 'Z') {
				s[i] = s[i] - 26;
			}
		}
		else if (s[i] >= 'a' && s[i] <= 'r') {
			s[i] = s[i] + 13;
			if (s[i] > 'z') {
				s[i] = s[i] - 26;
			}
		}
		else if (s[i] >= 's' && s[i] <= 'z') {	//아스키 코드값을 벗어나기 때문에 오버플로우가 나는걸 방지한다.
			s[i] = s[i] - 13;
		}
	}

	//for (int i = 0; i < s.size(); i++) {
	//	if (s[i] >= 'a' && s[i] <= 'm') {
	//		s[i] = s[i] + 13;
	//	}
	//	else if (s[i] >= 'n' && s[i] <= 'z') {
	//		s[i] = s[i] - 13;
	//	}
	//	else if (s[i] >= 'A' && s[i] <= 'M') {
	//		s[i] = s[i] + 13;
	//	}
	//	else if (s[i] >= 'N' && s[i] <= 'Z') {
	//		s[i] = s[i] - 13;
	//	}
	//}

	cout << s;
	return 0;
}