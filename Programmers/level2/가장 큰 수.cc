#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const int& n1, const int& n2) {
	string num1 = to_string(n1);
	string num2 = to_string(n2);

	return num1 + num2 > num2 + num1;
}

string solution(vector<int> numbers) {
	string answer;

	sort(numbers.begin(), numbers.end(), cmp);

	if (numbers[0] == 0)	return "0";

	for (int i : numbers) {
		string num = to_string(i);
		answer = answer + num;
	}

	return answer;
}

int main() {
	vector<int> vec{ 0, 0};
	cout << solution(vec);
	return 0;
}