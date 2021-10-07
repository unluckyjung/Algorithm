#include <bits/stdc++.h>

using namespace std;

vector<string> results;
int fightCount;


struct fighter {
    int weight;
    int number;
    int winCount;
    int fightCount;
    double winRate;
    int bonusWinCount;
};

bool cmp(const fighter &f1, const fighter &f2) {
  if (abs(f1.winRate - f2.winRate) < 0.000000001) {
    if (f1.bonusWinCount == f2.bonusWinCount) {
      if (f1.weight == f2.weight) {
        return f1.number < f2.number;
      } else {
        return f1.weight > f2.weight;
      }
    } else {
      return f1.bonusWinCount > f2.bonusWinCount;
    }
  } else {
    return f1.winRate > f2.winRate;
  }
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
  vector<int> answer;

  results = head2head;
  fightCount = weights.size();
  vector<fighter> fighterInfos;

  for (int i = 0; i < fightCount; ++i) {
    fighter f = {weights[i], i, 0, 0, 0.000, 0};
    for (int ii = 0; ii < fightCount; ++ii) {
      char result = results[i][ii];
      if (result == 'N') continue;

      f.fightCount++;
      if (result == 'W') {
        f.winCount++;
        int otherWeight = weights[ii];
        if (f.weight < otherWeight) f.bonusWinCount++;
      }
    }

    if (f.fightCount != 0) {
      f.winRate = (double) f.winCount / f.fightCount * 100.0;
    }
    fighterInfos.push_back(f);
  }

  sort(fighterInfos.begin(), fighterInfos.end(), cmp);

  for (auto f : fighterInfos) {
    answer.push_back(f.number + 1);
  }

  return answer;
}