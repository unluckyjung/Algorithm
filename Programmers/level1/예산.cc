#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//완탐문제 X

int solution(vector<int> d, int budget) {
	int answer = 0;

	sort(d.begin(), d.end());
	
	for (auto it = d.begin(); it != d.end(); ++it) {
		budget -= *it;
		if (budget < 0) return answer;
		answer++;
	}
	return answer;
}