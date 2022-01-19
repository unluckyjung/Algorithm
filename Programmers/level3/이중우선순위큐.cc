#include<bits/stdc++.h>
using namespace std;

multiset<int> ms;

void Parsing(string str) {
    stringstream st(str);

    char cmd;
    int val;
    while (st >> cmd) {
        st >> val;

        if (cmd == 'I') {
            ms.insert(val);
        } else if (cmd == 'D') {
            if (ms.size() == 0) return;

            if (val == 1) {
                int maxValue = *ms.rbegin();
                ms.erase(ms.erase(maxValue));
            } else {
                int _min = *ms.begin();
                ms.erase(ms.begin());
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
    } else {
        answer.push_back(*ms.rbegin());
        answer.push_back(*ms.begin());
    }

    return answer;
}