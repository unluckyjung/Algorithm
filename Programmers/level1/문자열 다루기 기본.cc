#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
	//bool answer = true;

	if ((int)s.size() == 4 || (int)s.size() == 6) {
		for (int i = 0; i < (int)s.size(); ++i) {
			if (!isdigit(s[i])) return false;
		}
		return true;
	}
	return false;
}