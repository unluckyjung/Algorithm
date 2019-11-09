#include<bits/stdc++.h>

using namespace std;

int state[5] = { 5, 100, 10, 5, 2 };
int receipt[5] = { 4, 50, 10, 10, 4 };

int price[5] = { 10000, 3000, 1000, 2000, 1000 };
int amount[5] = { 10, 100, 30, 50, 10 };
//10kg 100g 30cm 50g 10g

vector<int> answer;


void buy(const string &eat) {

	int pay = 0;

	if (eat == "1.0") {
		for (int i = 0; i < 5; ++i) {
			while (state[i] < receipt[i]) {
				state[i] += amount[i];
				pay += price[i];
			}
			state[i] -= receipt[i];
		}
		cout << pay << " ";
		answer.push_back(pay);
	}
	else if (eat == "1.5") {
		for (int i = 0; i < 4; ++i) {
			while ((double)state[i] < (double)receipt[i]*1.5) {
				state[i] += amount[i];
				pay += price[i];
			}
			state[i] -= receipt[i]*1.5;
		}

		while (state[4] < receipt[4] * 1.5 / 2) {
			state[4] += amount[4];
			pay += price[4];
		}

		state[4] -= receipt[4] * 1.5;

		cout << pay << " ";
		answer.push_back(pay);

	}
	else if (eat == "2.0") {
		for (int i = 0; i < 5; ++i) {
			while (state[i] < receipt[i]*2) {
				state[i] += amount[i];
				pay += price[i];
			}
			state[i] -= receipt[i] * 2.0;
		}
		cout << pay << " ";
		answer.push_back(pay);
	}
	else if (eat == "2.5") {
		for (int i = 0; i < 4; ++i) {
			while ((double)state[i] < receipt[i] * 2.5) {
				state[i] += amount[i];
				pay += price[i];
			}
			state[i] -= receipt[i] * 2.5;
		}

		while ((double)state[4] < receipt[4] * 2.5 / 2) {
			state[4] += amount[4];
			pay += price[4];
		}

		state[4] -= receipt[4] * 2.5;

		cout << pay << " ";
		answer.push_back(pay);

	}
}

vector<int> solution(vector<string> history) {
	//vector<int> answer;

	for (int i = 0; i < (int)history.size(); ++i) {
		if (history[i] == "1.0" or history[i] == "1.5" or history[i] == "2.0" or history[i] == "2,5") {
			buy(history[i]);
		}
		else {
			answer.clear();
			answer.push_back(-1); return answer;
		}
		
	}
	return answer;
}

int main() {
	vector<string> vec1{ "1.0","2.0", "1.5"};

	solution(vec1);
}