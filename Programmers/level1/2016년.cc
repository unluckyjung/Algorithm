#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> DAY{ "SUN" ,"MON", "TUE", "WED", "THU", "FRI", "SAT" };
//vector<string> DAY{ "THU" ,"FRI", "SAT", "SUN" ,"MON", "TUE", "WED" };
int MONTH_DAY[] = { 0,0,31,29,31,30,31,30,31,31,30,31,30,31 };

int month_to_day(int a) {

	int ret = 0;

	while (a > 1) {
		ret += MONTH_DAY[a];
		a--;
	}
	return ret;
}

string solution(int a, int b) {

	int day = month_to_day(a) + b;
	string answer = DAY[(day + 4) % 7];
	return answer;
}

int main() {
	cout << solution(5, 24);
	return 0;
}