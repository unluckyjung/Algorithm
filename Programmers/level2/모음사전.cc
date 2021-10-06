#include <bits/stdc++.h>

using namespace std;

map<string, int> wordOrder;
vector<char> alphas{'A', 'E', 'I', 'O', 'U'};
int cnt = 0;

void func(string curWord){
    if (curWord.size() == 5) return;

    for (char alpha : alphas){
        string word = (curWord + alpha);
        cnt++;
        wordOrder[word] = cnt;
        func(word);
    }
}

int solution(string inputWord){
    int answer = 0;
    func("");

    answer = wordOrder[inputWord];
    return answer;
}
