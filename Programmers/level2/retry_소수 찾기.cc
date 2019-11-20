#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 10000000
using namespace std;

int prime[MAX];
bool visit[MAX];

int solution(string s) {

	for (int i = 2; i < MAX; ++i) {
		for (int ii = i; ii < MAX; ii += i) {
			prime[ii]++;
		}
	}

	int answer = 0;

	int size = (int)s.size();
	sort(s.begin(), s.end());

	do {
		for (int i = 1; i <= size; ++i) {
			int n;
			n = stoi(s.substr(0, i));
			if (!visit[n] && prime[n] == 1) {
				visit[n] = true;
				answer++;
			}
		}
	} while (next_permutation(s.begin(), s.end()));

	return answer;
}

int main() {

	cout << solution("17");
	return 0;
}