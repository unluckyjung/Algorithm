#include <bits/stdc++.h>

using namespace std;

int tree[1000002];
int treeCount, needTreeSum;
int maxTreeHeight, answer;

bool isEnoughTreeSum(int sawHeight) {
  long long cutTreeSum = 0;
  for (int i = 0; i < treeCount; ++i) {
    if (tree[i] <= sawHeight) continue;
    cutTreeSum += (tree[i] - sawHeight);
  }
  return cutTreeSum >= needTreeSum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> treeCount >> needTreeSum;
  for (int i = 0; i < treeCount; ++i) {
    cin >> tree[i];
    maxTreeHeight = max(maxTreeHeight, tree[i]);
  }

  int st = 0;
  int ed = maxTreeHeight;

  while (st <= ed) {
    int mid = st + (ed - st) / 2;
    if (isEnoughTreeSum(mid)) {
      answer = mid;
      st = mid + 1;
    } else {
      ed = mid - 1;
    }
  }
  cout << answer << "\n";

  return 0;
}