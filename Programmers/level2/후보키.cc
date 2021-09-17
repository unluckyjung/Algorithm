#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> usedBitSet;
vector<vector<string>> relations;
int answer;

bool isUsedBit(int candidateKey) {
  for (int usedKey : usedBitSet) {
    if ((candidateKey & usedKey) == usedKey) return true;
  }
  return false;
}

void select(int bit) {
  if (isUsedBit(bit)) return;
  set<string> keySet;

  for (vector<string> data : relations) {
    string keyCandidate;
    for (int i = 0; i < m; ++i) {
      if ((bit & (1 << i)) == 0) continue;
      keyCandidate += data[i];
    }
    keySet.insert(keyCandidate);
  }

  if (keySet.size() != n) return;
  usedBitSet.push_back(bit);
  answer++;
}

int solution(vector<vector<string>> relation) {
  n = relation.size();
  m = relation[0].size();
  relations = relation;

  for (int i = 1; i < (1 << m); ++i) {
    select(i);
  }

  return answer;
}

int main() {
  int ans = solution({
                             {"100", "ryan",   "music",    "2"},
                             {"200", "apeach", "math",     "2"},
                             {"300", "tube",   "computer", "3"},
                             {"400", "con",    "computer", "4"},
                             {"500", "muzi",   "music",    "3"},
                             {"600", "apeach", "music",    "2"}
                     });

  cout << ans;
  return 0;
}