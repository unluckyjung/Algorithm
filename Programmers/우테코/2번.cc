#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string logs) {
	vector<int> answer(24,0);

	for (int i = 11; i < (int)logs.size(); i+=20) {
		string ret = logs.substr(i, 2);
		int UTC_time = stoi(ret);
		int kor_time = (UTC_time + 9) % 24;
		cout << kor_time;
		answer[kor_time]++;
	}
	return answer;
}

int main() {
	string str = "2019/05/01 00:59:19\n2019/06/01 01:35:20\n2019/08/01 02:01:22";


	solution(str);

	return 0;
}