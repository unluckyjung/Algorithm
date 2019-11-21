#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;

	for (int i = 1; i <= red; ++i) {
		int red_row = i;
		int red_col = red / i;
		if (red_row >= red_col && red % i == 0) {
			int brown_row = red_row + 2;
			int brown_col = red_col + 2;

			//cout << brown_col << " " << brown_row;

			if ((brown_col * brown_row - red) == brown) {
				answer.push_back(brown_row);
				answer.push_back(brown_col);
				break;
			}
		}
	}
	return answer;
}