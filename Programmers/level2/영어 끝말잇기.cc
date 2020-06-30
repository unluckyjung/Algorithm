#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> record;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int cnt = 0;
    char finChar = words[0][0];
    for (const string &str : words) {
        if (record[str] == true or finChar != str[0]) {
            answer.push_back((cnt % n) + 1);
            answer.push_back(cnt / n + 1);
            break;
        }
        record[str] = true;
        finChar = *(str.rbegin());
        cnt++;
    }

    if (answer.empty()) {
        answer.resize(2, 0);
    }

    return answer;
}

int main() {

    return 0;
}