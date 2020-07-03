#if 01

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    a--, b--;

    while (a != b) {
        a /= 2;
        b /= 2;
        answer++;
    }
    
    return answer;
}


#else

#include <iostream>
#include <vector>

using namespace std;

int answer, n;

vector<int> curRound, nxtRound;

int RoundStart(int a, int b) {
    answer++;

    int roundCnt = curRound.size();

    for (int i = 0; i < roundCnt; i += 2) {
        int maybeA = curRound[i];
        int maybeB = curRound[i + 1];

        if ((maybeA == a and maybeB == b) or (maybeA == b and maybeB == a)) return answer;

        if (maybeA == a or maybeB == a) nxtRound.push_back(a);
        else if (maybeA == b or maybeB == b) nxtRound.push_back(b);
        else nxtRound.push_back(maybeA);
    }
    return -1;
}

void Init() {
    curRound.resize(n);
    for (int i = 1; i <= n; ++i) {
        curRound[i - 1] = i;
    }
}

int solution(int nn, int a, int b)
{
    n = nn;
    Init();

    while (1) {
        if (RoundStart(a, b) != -1) break;
        curRound = nxtRound;
        nxtRound.clear();
    }
    return answer;
}

#endif