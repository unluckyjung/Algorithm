#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> let) {
	int answer = 0;

	for (int i = 0; i <= let.size(); ++i) {
		int tmp = 0;
		for (int ii = 0; ii < let.size(); ++ii) {
			if (let[ii] >= i)	tmp++;
		}
		if (tmp >= i && i >= let.size() - tmp)	answer = max(i, answer);
	}
	return answer;
}

int main() {
	vector<int> vec{ 4,3,3,3,3 };
	cout << solution(vec);
	return 0;
}