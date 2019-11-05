#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string S;
int str_size;

int head_num_check(int n) {
	int ret = 0;
	while (n) {
		ret++;
		n /= 10;
	}
	return ret;
}

int solve(int cut_size) {
	int head_num = 1;
	int new_str_size = 0;

	for (int i = 0; i < str_size; i += cut_size) {
		if (i + cut_size * 2 > str_size || S.substr(i, cut_size) != S.substr(i + cut_size, cut_size)) {
			new_str_size += min(cut_size, str_size - i);

			if (head_num > 1) {
				new_str_size += head_num_check(head_num);
			}
			head_num = 1;
		}
		else head_num++;
	}
	return new_str_size;
}

int solution(string s) {
	S = s;
	str_size = s.size();
	int ans = str_size;
	
	for (int i = 1; i <= str_size / 2; ++i) {
		ans = min(ans, solve(i));
	}

	return ans;
}

//main ===============================
int main() {
	cout << solution("abcabcdede");

	return 0;
}