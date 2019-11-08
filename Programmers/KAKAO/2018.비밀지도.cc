#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;

string to_binary(int k) {
	string ret;

	while (k) {
		ret.push_back((k % 2) + '0');
		k /= 2;
	}

	while (ret.size() < N) {
		ret.push_back('0');
	}

	return ret;
}


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	//vector<string> answer;
	N = n;
	vector<string> board1;
	vector<string> board2;

	for (int i = 0; i < n; ++i) {
		string tmp = to_binary(arr1[i]);
		string correct;

		while (!tmp.empty()) {
			correct.push_back(tmp.back());
			tmp.pop_back();
		}
		board1.push_back(correct);
	}

	for (int i = 0; i < n; ++i) {
		string tmp = to_binary(arr2[i]);
		string correct;

		while (!tmp.empty()) {
			correct.push_back(tmp.back());
			tmp.pop_back();
		}
		board2.push_back(correct);
	}

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			if (board1[i][ii] == '1' || board2[i][ii] == '1') board1[i][ii] = '#';
			else if (board1[i][ii] == '0' || board2[i][ii] == '0') board1[i][ii] = ' ';
		}
	}

	return board1;
}