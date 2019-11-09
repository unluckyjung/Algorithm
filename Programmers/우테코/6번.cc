#include<bits/stdc++.h>

using namespace std;


vector<string> solution(vector<vector<string>> forms) {
	vector<string> answer;

	for (int i = 0; i < (int)forms.size(); ++i) {
		string email = forms[i][0];
		string name = forms[i][1];

		for (int ii = i + 1; ii < (int)forms.size(); ++ii) {
			string compare_email = forms[ii][0];
			string compare_name = forms[ii][1];

			bool find_same = false;
			for (int j = 0; j < (int)name.size(); j += 3) {
				for (int jj = 0; jj < (int)compare_name.size(); jj += 3) {

					string tmp1 = name.substr(j, 3);
					string tmp2 = name.substr(jj, 3);

					if (name[j] == compare_name[jj]) {
						if (j + 2 >= name.size())continue;
						if (jj + 2 >= compare_name.size())continue;

						string tmp11 = name.substr(j + 3, 3);
						string tmp22 = name.substr(jj + 3, 3);
						if (tmp11 == tmp22) {
							answer.push_back(email);
							answer.push_back(compare_email);
							find_same = true;
							cout << "pushed";
							break;
						}
					}
				}
				if (find_same)break;
			}

		}
	}

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	return answer;
}

int main() {

	vector<vector<string>> vec1{ {"jm@email.com", "제이엠"},{"jason@email.com", "우이엠"} };
	solution(vec1);

	return 0;
}