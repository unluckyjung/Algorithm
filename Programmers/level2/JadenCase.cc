#if 00

#include<bits/stdc++.h>
using namespace std;

string answer;


string ChangeToJadenCase(string str) {
    for (int i = 0; i < str.size(); ++i) {
        if (i == 0) {
            if (!(isalpha(str[i]) && islower(str[i]))) continue;
            str[i] -= 'a' - 'A';
        }
        else {
            if (!(isalpha(str[i]) && isupper(str[i]))) continue;
            str[i] += 'a' - 'A';
        }
    }
    return str;
}

void StringSplit(string s) {

    string tmp = "";
    for (int i = 0; i < s.size() ; ++i) {
        if (s[i] == ' ') answer += ' ';
        else {
            int ii;
            for (ii = i; ii < s.size(); ++ii) {
                if (s[ii] != ' ') tmp.push_back(s[ii]);
                else {
                    answer += ChangeToJadenCase(tmp) + ' ';
                    tmp = "";
                    break;
                }
            }
            i = ii;
        }
    }

    if (tmp.size() != 0) answer += ChangeToJadenCase(tmp);
}

string solution(string s) {
    StringSplit(s);
    return answer;
}

int main() {

    //cout << solution("for          the last week");

    cout << (char)tolower('3');
}

#else

#include<bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";

    for (int i = 0; i < s.size(); ++i) {
        if (i == 0) answer += toupper(s[i]);
        else {
            char before = s[i - 1];
            if(before == ' ') answer += toupper(s[i]);
            else answer += tolower(s[i]);
        }
    }

    return answer;
}

#endif