#include <bits/stdc++.h>

using namespace std;

map<string, set<string>> toReportMap;
map<string, int> reportedCount;
map<string, map<string, int>> isReported;
vector<string> banList;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  vector<int> answer((int) id_list.size(), 0);

  for (auto list : report) {
    string from, to;
    stringstream ss(list);
    ss >> from >> to;

    toReportMap[from].insert(to);

    if (isReported[from][to]) continue;
    isReported[from][to] = true;
    reportedCount[to]++;
  }

  for (auto[id, count] : reportedCount) {
    if (count >= k) {
      banList.push_back(id);
    }
  }

  for (int i = 0; i < id_list.size(); ++i) {
    string id = id_list[i];

    for (string banId : banList) {
      set<string> reportIds = toReportMap[id];
      if (find(reportIds.begin(), reportIds.end(), banId) != reportIds.end()) answer[i]++;
    }
  }

  return answer;
}
