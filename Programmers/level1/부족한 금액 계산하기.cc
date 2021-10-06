#include<bits/stdc++.h>

using namespace std;

long long solution(int price, int money, int count) {
  long long answer = 0;
  long long needMoney = (long long) price * count * (count + 1) / 2;

  answer = money - needMoney;
  if (answer >= 0) return 0;
  return abs(answer);
}