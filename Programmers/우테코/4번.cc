#include<bits/stdc++.h>
using namespace std;

vector<bool> solution(vector<string> infos, vector<string> actions) {
	vector<bool> answer;
	map<string, string> m;

	for (int i = 0; i < (int)infos.size(); ++i) {
		string str = infos[i];

		for (int ii = 0; ii < (int)str.size(); ++ii) {
			if (str[ii] == ' ') {
				m[str.substr(0, ii)] = str.substr(ii+1);
			}
		}
	}

	bool logined = false;
	vector<string> bucket;

	for (int i = 0; i < (int)actions.size(); ++i) {
		string act = actions[i];

		if (act[0] == 'L') {
			if (logined) answer.push_back(false);
			else {
				for (int ii = 6; ii < act.size(); ++ii) {
					if (act[ii] == ' ') {
						string tmp_id = act.substr(6, ii - 6);
						string tmp_pwd = act.substr(ii + 1);
						if (m[tmp_id] == tmp_pwd) {
							logined = true;	answer.push_back(true);
						}
						else answer.push_back(false);
					}
				}
			}
		}
		else if (act[0] == 'A') {
			if (!logined) answer.push_back(false);
			else {
				bucket.push_back(act.substr(4)); answer.push_back(true);
			}
		}
		else if (act[0] == 'O') {
			if (!logined or bucket.empty()) answer.push_back(false);
			else {
				answer.push_back(true);	bucket.clear();
			}
		}
	}

	return answer;
}