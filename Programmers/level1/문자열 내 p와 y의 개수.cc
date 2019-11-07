#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	//bool answer = true;

	int pcount = 0, ycount = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == 'p' or s[i] == 'P') pcount++;
		else if (s[i] == 'y' or s[i] == 'Y') ycount++;
	}

	return pcount == ycount;
}