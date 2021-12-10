#include <bits/stdc++.h>

using namespace std;

int solution(int n) {

  // 홀수면 항상 2
  if (n % 2 != 0) return 2;

  for (int i = 2; i < n; ++i) {
    if (n % i == 1) return i;
  }
}