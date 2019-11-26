#include<bits/stdc++.h>
#include<regex>
using namespace std;

int main() {
	cin.tie(NULL);
	vector<int> vec;
	int n;	cin >> n;
	while (n--) {
		int num;	cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	int sum = 0;
	vector<int> vec2;
	vec2.push_back(vec[0]);	sum += vec2[0];
	for (int i = 1; i < (int)vec.size(); ++i) {
		vec2.push_back(vec[i] + vec2[i - 1]);
		sum += vec2[i];
	}
	cout << sum;
	return 0;
}