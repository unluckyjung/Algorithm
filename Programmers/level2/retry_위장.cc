#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> cloth) {
	
	int answer = 1;
	map<string, int> m;

	for (int i = 0; i < (int)cloth.size(); ++i) {
		string clo = cloth[i].back();
		m[clo]++;
	}

	for (auto it = m.begin(); it != m.end(); ++it) {
		//입지 않는 경우도 고려해야하므로 +1
		answer = answer * ((it->second)+1);
	}
	return answer -1 ;
}