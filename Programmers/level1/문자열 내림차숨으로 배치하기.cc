#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s) {

	sort(s.begin(), s.end(), greater<int>());
	
	return s;
}