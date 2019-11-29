#include<bits/stdc++.h>

using namespace std;

string A, B;
string s;

int A_score, B_score;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, s);

	for (char c : s) {
		if (isdigit(c))	A.push_back(c);
	}

	getline(cin, s);
	for (char c : s) {
		if (isdigit(c))	B.push_back(c);
	}


	bool draw = true;
	bool winnerflag = false;


	for (int i = 0; i < (int)A.size(); ++i) {
		if (A[i] > B[i]) {
			A_score += 3;
			winnerflag = false;
			draw = false;
		}
		else if (A[i] < B[i]) {
			B_score += 3;
			winnerflag = true;
			draw = false;
		}
		else {
			A_score++;
			B_score++;
		}
	}

	cout << A_score << ' ' << B_score << '\n';
	if (A_score > B_score) cout << "A\n";
	else if (A_score < B_score) cout << "B\n";
	else {
		if (draw)cout << "D\n";
		else {
			if (!winnerflag)	cout << "A\n";
			else cout << "B\n";
		}
	}
	return 0;
}