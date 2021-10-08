#include <bits/stdc++.h>

using namespace std;

int inTime[1002];
int outTime[1002];

vector<int> solution(vector<int> enter, vector<int> leave) {
  int peopleCount = enter.size();
  vector<int> answer(peopleCount);

  for (int i = 0; i < peopleCount; ++i) {
    inTime[i] = find(enter.begin(), enter.end(), i + 1) - enter.begin();
    outTime[i] = find(leave.begin(), leave.end(), i + 1) - leave.begin();
  }

  for (int a = 0; a < peopleCount; ++a) {
    for (int b = 0; b < peopleCount; ++b) {
      if (inTime[a] < inTime[b] && outTime[a] > outTime[b]) {
        answer[a]++;
        answer[b]++;
      } else if (inTime[a] > inTime[b] && outTime[a] > outTime[b]) {
        for (int c = 0; c < peopleCount; ++c) {
          if (inTime[c] > inTime[a] && outTime[c] < outTime[b]) {
            answer[a]++;
            answer[b]++;
            break;
          }
        }
      }
    }
  }
  return answer;
}