#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> prices, vector<int> discounts) {

	sort(prices.rbegin(), prices.rend());
	sort(discounts.begin(), discounts.end());
	int answer = 0;

	for (int i = 0; i < (int)prices.size(); ++i) {
		if (!discounts.empty()) {
			prices[i] = (double)prices[i] * (100.0 - discounts.back()) / 100.0;
			discounts.pop_back();
		}
		//cout << prices[i];
		answer += prices[i];
	}
	return answer;
}