#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
	int answer = 0;
	string str_n = to_string(n);
	
	for (int i = 0; i < (int)str_n.size(); ++i) {
		answer += str_n[i] - '0';
	}

	return answer;
}