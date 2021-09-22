#include <bits/stdc++.h>

using namespace std;

struct DeliveryData {
    int from, to;
    int boxCount;
};

bool cmp(const DeliveryData &d1, const DeliveryData &d2) {
  if (d1.to == d2.to) {
    return d1.from < d2.from;
  }
  return d1.to < d2.to;
}

vector<DeliveryData> deliveryData;
int truckWeight[2002];

int cityCount, truckLimit;
int inputCount;

int answer;


void delivery() {
  for (auto data : deliveryData) {
    int loadedCount = 0;
    for (int i = data.from; i < data.to; ++i) {
      loadedCount = max(loadedCount, truckWeight[i]);
    }

    int loadCount = min(data.boxCount, truckLimit - loadedCount);
    answer += loadCount;

    for (int i = data.from; i < data.to; ++i) {
      truckWeight[i] += loadCount;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> cityCount >> truckLimit;
  cin >> inputCount;

  while (inputCount--) {
    int from, to, boxCount;
    cin >> from >> to >> boxCount;
    deliveryData.push_back({from, to, boxCount});
  }

  sort(deliveryData.begin(), deliveryData.end(), cmp);
  delivery();

  cout << answer << "\n";

  return 0;
}
