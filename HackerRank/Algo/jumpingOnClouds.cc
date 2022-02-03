
#include <bits/stdc++.h>

using namespace std;

int jumpingOnClouds(vector<int> c) {
  int jumpCount[102] = {0, 1};
  for (int i = 2; i < (int) c.size(); ++i) {
    if (c[i] == 0) jumpCount[i] = min(jumpCount[i - 2], jumpCount[i - 1]) + 1;
    else jumpCount[i] = 102;
  }
  return jumpCount[(int) c.size() - 1];
}