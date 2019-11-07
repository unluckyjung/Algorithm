#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
	string subak = "수박";
	string answer;
	int roop = n / 2;

	while (roop) {
		answer += subak;	roop--;
	}

	if (n % 2 != 0) answer += "수";

	return answer;
}

int main() {

	cout << solution(4);

	return 0;
}