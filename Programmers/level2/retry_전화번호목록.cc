#include <string>
#include <vector>
#include <regex>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	for (string str1 : phone_book) {
		for (string str2 : phone_book) {
			if (str1 == str2)continue;
			if (str1.size() > str2.size()) {
				if (str1.substr(0, str2.size()) == str2)	return false;
			}
		}
	}
	
	return answer;
}