#include<string>
#include<vector>
#include<map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	
	map<string, int> m;

	while (!completion.empty()) {
		m[completion.back()]++;
		completion.pop_back();
	}

	while (!participant.empty()) {
		//if (m.find(participant.back()) == m.end() or m[participant.back()] == 0) {
		if (m[participant.back()] == 0) {
			//map의 특징상, 없는 값을 참조할경우 default 값인 0으로 만들고 map에 넣어두는것을 이용
			return participant.back();
		}
		m[participant.back()]--;
		participant.pop_back();
	}
}