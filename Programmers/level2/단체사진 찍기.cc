#include <bits/stdc++.h>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

string friends = "ACFJMNRT";


bool Is_Can(char cmd, int dist, int want_dist) {
	if (cmd == '=') return dist == want_dist;
	else if (cmd == '<') return dist < want_dist;
	else if (cmd == '>') return dist > want_dist;
}

int solution(int n, vector<string> data) {
    int answer = 0;

    do {
        int is_can = true;
        for (string d : data) {
            char a = d[0], b = d[2];
            char cmd = d[3];
            int want_dist = d[4] -'0';

            int dist = friends.find(a) - friends.find(b);
            dist = abs(dist) - 1;

            if(Is_Can(cmd, dist, want_dist)) continue;
            is_can = false;
            break;
        }
        if (is_can) answer++;

    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}

int main() {

    vector<string> data{ "N~F=0", "R~T>2" };

    cout << solution(2, data);

    return 0;
}