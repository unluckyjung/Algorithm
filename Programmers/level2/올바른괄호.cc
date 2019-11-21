#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	int check = 0;
	
	for (char ch : s) {
		if (ch == '(')check++;
		else check--;
		if (check < 0)	return false;
	}
	
	if (check != 0)	return false;
	return answer;
}