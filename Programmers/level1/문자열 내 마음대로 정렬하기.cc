#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N;

bool cmp(string& a, string& b) {

	if (a[N] == b[N]) {
		return a < b;
	}
	return a[N] < b[N];
}

vector<string> solution(vector<string> strings, int n) {
	//vector<string> answer;

	N = n;
	stable_sort(strings.begin(), strings.end(), cmp);

	return strings;
}