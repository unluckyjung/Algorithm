#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> STACK;

    for (const char& ch : s) {
        if (!STACK.empty() and STACK.top() == ch) {
            STACK.pop();
        }
        else STACK.push(ch);
    }

    STACK.empty() ? answer = 1 : answer = 0;
    return answer;
}

int main() {

    cout << solution("cdcd");
    return 0;
}