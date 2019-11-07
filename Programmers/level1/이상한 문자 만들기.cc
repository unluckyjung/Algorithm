#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	//string answer = "";

	int index = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == ' ') {
			index = 0; continue;
		}
		if (index & 1) {
			s[i] = tolower(s[i]);
			index++;
		}
		else {
			s[i] = toupper(s[i]);
			index++;
		}
	}
	return s;
}