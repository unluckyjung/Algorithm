#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
	string answer;

	int len = s.size();
	if (len & 1) {
		answer = s.substr(len / 2, 1);
	}
	else {
		answer = s.substr(len / 2 -1 , 2);
	}
	return answer;
}