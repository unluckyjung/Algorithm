#include <bits/stdc++.h>

using namespace std;

map<string, vector<int> > scoreMap;

vector<int> makeCombination(int selectCount, int totalCount) {
  vector<int> combination;
  for (int ii = 0; ii < totalCount - selectCount; ++ii) {
    combination.push_back(0);
  }
  for (int ii = 0; ii < selectCount; ++ii) {
    combination.push_back(1);
  }
  return combination;
}

vector<string> split(const string &str, char delimiter) {
  vector<string> vec;
  stringstream ss(str);

  string splitStr;
  while (getline(ss, splitStr, delimiter)) {
    vec.push_back(splitStr);
  }
  return vec;
}

void putScore(const vector<string> &infos) {
  for (const string &info : infos) {
    vector<string> splitInfos = split(info, ' ');

    int score = stoi(splitInfos[4]);

    for (int i = 1; i <= 4; ++i) {
      vector<int> combi = makeCombination(i, 4);
      do {
        string curInfo;
        for (int ii = 0; ii < (int) combi.size(); ++ii) {
          if (combi[ii] == 1) {
            curInfo += splitInfos[ii];
          }
        }
        scoreMap[curInfo].push_back(score);
      } while (next_permutation(combi.begin(), combi.end()));
    }


    scoreMap["all"].push_back(score);
  }

  for (auto &scores : scoreMap) {
    sort(scores.second.begin(), scores.second.end());
  }
}

vector<int> solution(vector<string> infos, vector<string> querys) {
  vector<int> answer;

  putScore(infos);

  for (const string &query : querys) {
    vector<string> queryInfos = split(query, ' ');
    string curInfo;
    int score = stoi(queryInfos[queryInfos.size() - 1]);

    for (int i = 0; i < (int) queryInfos.size() - 1; ++i) {
      string info = queryInfos[i];
      if (info == "-") continue;
      if (info == "and") continue;
      curInfo += info;
    }

    if (curInfo.empty()) {
      curInfo = "all";
    }

    const vector<int> &acceptQueryScores = scoreMap[curInfo];

    int scoreCount = acceptQueryScores.end() - lower_bound(acceptQueryScores.begin(), acceptQueryScores.end(), score);

    answer.push_back(scoreCount);
  }

  return answer;
}