#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> id;
vector<string> answer;

void GetResult(string record) {
    string result = "";

    stringstream ss(record);
    string cmd, uid, nickName;

    ss >> cmd;
    if (cmd == "Change") return;

    ss >> uid;
    result += id[uid] + "님이 ";
    if (cmd == "Enter") result += "들어왔습니다.";
    else if (cmd == "Leave") result += "나갔습니다.";

    answer.push_back(result);
}

void GetRealNickName(string record) {
    stringstream ss(record);
    string cmd, uid, nickName;

	ss >> cmd;

	if (cmd == "Leave") return;

	ss >> uid >> nickName;
	id[uid] = nickName;
}

vector<string> solution(vector<string> records) {

    for (string record : records) {
        GetRealNickName(record);
    }

    for (string record : records) {
        GetResult(record);
    }

    return answer;
}