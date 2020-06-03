#include<bits/stdc++.h>
using namespace std;

multiset<int> ms;

void Parsing(string str) {
    stringstream st(str);

    char cmd;
    int val;
    while (st >> cmd) {
        st >> val;

        if (cmd == 'I') ms.insert(val);
        else if (cmd == 'D') {
            if (ms.size() == 0) return;

            if (val == 1) {
                int _max = *ms.rbegin();
                ms.erase(ms.find(_max));
            }
            else {
                int _min = *ms.begin();
                ms.erase(ms.find(_min));
            }
        }
    }
}

vector<int> solution(vector<string> operations) {

    vector<int> answer;
    for (const auto& oper : operations) {
        Parsing(oper);
    }

    if (ms.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*ms.rbegin());
        answer.push_back(*ms.begin());
    }

    return answer;
}

int main() {
    vector<int> vec = solution({"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"});
    for (auto it : vec) {
        cout << it << " ";
    }
    return 0;
}