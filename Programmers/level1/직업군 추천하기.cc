#include <bits/stdc++.h>

using namespace std;


map<string, int> companyScores;
vector<string> companys[6];

vector<string> split(string inputStr, char delimiter) {
  vector<string> splited;
  stringstream ss(inputStr);

  string tmp;
  while (getline(ss, tmp, delimiter)) {
    splited.push_back(tmp);
  }
  return splited;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
  string answer = "";

  for (int i = 0; i < table.size(); ++i) {
    companys[i] = split(table[i], ' ');
  }

  int companyMaxScore = 0;

  for (int i = 0; i < 5; ++i) {
    vector<string> company = companys[i];
    string companyName = company[0];
    int companyScore = 0;

    for (int lan = 0; lan < languages.size(); ++lan) {
      for (int companyLan = 1; companyLan < 6; ++companyLan) {
        if (company[companyLan] == languages[lan]) {
          companyScore += (6 - companyLan) * preference[lan];
          break;
        }
      }
    }
    companyScores[companyName] = companyScore;
    companyMaxScore = max(companyMaxScore, companyScore);
  }

  for (auto[name, score] : companyScores) {
    if (score == companyMaxScore) return name;
  }

  return answer;
}