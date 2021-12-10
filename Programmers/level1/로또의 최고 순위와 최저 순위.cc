#include <bits/stdc++.h>

using namespace std;

bool isWinNumber[46];

int getResult(int matchCount) {
  if (matchCount <= 1) return 6;
  return 7 - matchCount;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
  vector<int> answer;

  int matchCount = 0;
  int zeroCount = 0;

  for (int num: win_nums) {
    isWinNumber[num] = true;
  }

  for (int num : lottos) {
    if (num == 0) {
      zeroCount++;
    } else {
      if (isWinNumber[num]) matchCount++;
    }
  }

  answer = {getResult(matchCount + zeroCount), getResult(matchCount)};

  return answer;
}