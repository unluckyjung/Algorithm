#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

	vector<int> student(n, 1);

	for (int i = 0; i < (int)lost.size(); ++i) {
		student[lost[i] - 1]--;
		//student[lost[i]]--;
		//처음에 이렇게 잘못 써서 틀렸다.
		//3번 사람은 student[3]에 넣는것이 아닌 lost[3-1]에 넣어야한다.
	}

	for (int i = 0; i < (int)reserve.size(); ++i) {
		student[reserve[i] - 1]++;
	}

	for (int i = 0; i < n; ++i) {
		if (student[i] == 0 && i + 1 < n && student[i + 1] > 1) {
			student[i]++;
			student[i + 1]--;
		}
		else if (student[i] == 0 && i - 1 >= 0 && student[i - 1] > 1) {
			student[i]++;
			student[i - 1]--;
		}
	}

	int answer = 0;
	for (auto it : student) {
		if (it >= 1) answer++;
	}

	return answer;
}


int main() {
	vector<int> vec1{ 2,4 };
	vector<int> vec2{ 1,3,5 };
	cout << solution(5, vec1, vec2);

	return 0;
}
