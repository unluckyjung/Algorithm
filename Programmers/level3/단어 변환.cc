#include <string>
#include <vector>
#include <climits>

using namespace std;
string targetWord;
vector<string> words;
int answer = INT_MAX;

bool visited[52];

bool isOnlyOneDiff(string w1, string w2) {
    int diffCount = 0;
    for (int i = 0; i < (int)w1.size(); ++i) {
        if (w1[i] != w2[i]) diffCount++;
    }

    if (diffCount == 1) return true;
    else return false;
}

void dfs(string curWord, int curCount) {
    if (curWord == targetWord) {
        answer = min(answer, curCount);
        return;
    }

    for (int i = 0; i < (int)words.size(); ++i) {
        string nextWord = words[i];
        if (visited[i]) continue;
        if (isOnlyOneDiff(curWord, nextWord)) {
            visited[i] = true;
            dfs(nextWord, curCount + 1);
            visited[i] = false;
        }
    }
}

int solution(string b, string t, vector<string> ws) {
    targetWord = t;
    words = ws;

    dfs(b, 0);
    if (answer == INT_MAX) answer = 0;
    return answer;
}