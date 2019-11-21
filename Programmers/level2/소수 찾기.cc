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


#include <string>
#include <vector>
#include <algorithm>

#define MAX 10000000

int prime[MAX];
bool used[MAX];

using namespace std;

int solution2(string numbers) {
	int answer = 0;
	int size = numbers.size();

	for (int i = 2; i < MAX; ++i) {
		for (int ii = i; ii < MAX; ii += i) {
			prime[ii]++;
		}
	}

	sort(numbers.begin(), numbers.end());

	do {
		for (int i = 0; i < size; ++i) {
			int num = stoi(numbers.substr(i));
			if (prime[num] == 1 && !used[num]) {
				used[num] = true;
				answer++;
			}
		}
	} while (next_permutation(numbers.begin(), numbers.end()));
	return answer;
}

int main() {

	cout << solution("17");
	return 0;
}