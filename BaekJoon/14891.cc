#include<bits/stdc++.h>
using namespace std;

deque<int> gear[5];
int gear_rotate[5];

int cmd_num;
int gear_num, cmd;

void rotation() {
	for (int i = 1; i <= 4; ++i) {
		if (gear_rotate[i] == 0)continue;

		if (gear_rotate[i] == 1) {
			int tmp = gear[i].back();	gear[i].pop_back();
			gear[i].push_front(tmp);
		}
		else if (gear_rotate[i] == -1) {
			int tmp = gear[i].front();	gear[i].pop_front();
			gear[i].push_back(tmp);
		}
	}
}


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	for (int i = 1; i <= 4; ++i) {
		string line;	cin >> line;
		for (int ii = 0; ii < 8; ++ii) {
			gear[i].push_back(line[ii] - '0');
		}
	}

	cin >> cmd_num;

	while (cmd_num--) {
		cin >> gear_num;
		cin >> gear_rotate[gear_num];

		if (gear_num == 1) {
			if (gear[1][2] != gear[2][6])	gear_rotate[2] = gear_rotate[1] * -1;
			if (gear_rotate[2] != 0) {
				if (gear[2][2] != gear[3][6])	gear_rotate[3] = gear_rotate[2] * -1;
			}
			if (gear_rotate[3] != 0) {
				if (gear[3][2] != gear[4][6])	gear_rotate[4] = gear_rotate[3] * -1;
			}
		}

		if (gear_num == 2) {
			if (gear[2][2] != gear[3][6])	gear_rotate[3] = gear_rotate[2] * -1;
			if (gear[1][2] != gear[2][6])	gear_rotate[1] = gear_rotate[2] * -1;

			if (gear_rotate[3] != 0) {
				if (gear[3][2] != gear[4][6])	gear_rotate[4] = gear_rotate[3] * -1;
			}
		}

		if (gear_num == 3) {
			if (gear[3][2] != gear[4][6])	gear_rotate[4] = gear_rotate[3] * -1;
			if (gear[2][2] != gear[3][6])	gear_rotate[2] = gear_rotate[3] * -1;

			if (gear_rotate[2] != 0) {
				if (gear[1][2] != gear[2][6])	gear_rotate[1] = gear_rotate[2] * -1;
			}
		}

		if (gear_num == 4) {
			if (gear[3][2] != gear[4][6])	gear_rotate[3] = gear_rotate[4] * -1;
			if (gear_rotate[3] != 0) {
				if (gear[2][2] != gear[3][6])	gear_rotate[2] = gear_rotate[3] * -1;
			}
			if (gear_rotate[2] != 0) {
				if (gear[1][2] != gear[2][6])	gear_rotate[1] = gear_rotate[2] * -1;
			}
		}

		rotation();
		memset(gear_rotate, 0, sizeof(gear_rotate));
	}

	int sum = 0;
	sum += gear[1][0];
	sum += gear[2][0] * 2;
	sum += gear[3][0] * 4;
	sum += gear[4][0] * 8;

	cout << sum;
	return 0;
}