#include <string>
#include <vector>

using namespace std;

string solution(int num) {
	string answer;
	num & 1 ? answer = "Odd" : answer = "Even";
	return answer;
}