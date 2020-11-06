#include <bits/stdc++.h>

using namespace std;
vector<string> answer;

unordered_map<string, vector<string>> connectMap;
unordered_map<string, unordered_map<string, int>> leftTicketCount;
int maxTicektCount;

bool dfs(string startAirport, int usedTicketCount) {
    if (maxTicektCount == usedTicketCount) {
        return true;
    }

    for (string Airport : connectMap[startAirport]) {

        if (leftTicketCount[startAirport][Airport] == 0) continue;
        leftTicketCount[startAirport][Airport]--;

        answer.push_back(Airport);
        if (dfs(Airport, usedTicketCount + 1)) return true;
        answer.pop_back();
        leftTicketCount[startAirport][Airport]++;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    maxTicektCount = tickets.size();
    for (auto ticket : tickets) {
        connectMap[ticket[0]].push_back(ticket[1]);
        leftTicketCount[ticket[0]][ticket[1]]++;
    }

    for (auto ticket : tickets) {
        sort(connectMap[ticket[0]].begin(), connectMap[ticket[0]].end());
    }

    answer.push_back("ICN");
    dfs("ICN", 0);
    return answer;
}