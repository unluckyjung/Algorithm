#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>> maxHeap;
priority_queue<int, vector<int>, greater<>> minHeap;

int n;

void moveTopData();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  cin >> n;

  int num;

  for (int i = 0; i < n; ++i) {
    cin >> num;
    if (i == 0) {
      maxHeap.push(num);
      cout << maxHeap.top() << "\n";
      continue;
    }

    int pivot = maxHeap.top();
    if (num >= pivot) minHeap.push(num);
    else maxHeap.push(num);

    moveTopData();

    cout << maxHeap.top() << "\n";
  }

  return 0;
}

void moveTopData() {
  if (maxHeap.size() < minHeap.size()) {
    maxHeap.push(minHeap.top());
    minHeap.pop();
  } else if (maxHeap.size() - minHeap.size() >= 2) {
    minHeap.push(maxHeap.top());
    maxHeap.pop();
  }
}
