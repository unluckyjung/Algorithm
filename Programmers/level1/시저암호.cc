#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
	//string answer;

	int A = 'Z' - 'A' + 1;
	int a = 'z' - 'a' + 1;

	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] >= 'A' and s[i] <= 'Z') {
			s[i] += n;
			if (s[i] > 'Z')	s[i] -= A;
		}
		else if (s[i] >= 'a' and s[i] <= 'z') {
			int tmp = s[i] + n;
			//s[i] += n;
			//z의 경우 오버플로가 나므로 잠시 int로 연산 후 되돌림.
			if (tmp > 'z') {
				tmp -= A;
				s[i] = char(tmp);
			}
			else s[i] = char(tmp);
		}
	}
	return s;
}

int main() {
	cout << solution("aaaa", 4);
}