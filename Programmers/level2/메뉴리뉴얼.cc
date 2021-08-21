#include <bits/stdc++.h>

using namespace std;

map<string, int> menuOrderedCount[12];
vector<string> orders;
vector<int> course;
vector<string> answer;


vector<int> makeCombination(const string &order, int menuCount) {
  vector<int> combination;
  for (int ii = 0; ii < order.size() - menuCount; ++ii) {
    combination.push_back(0);
  }
  for (int ii = 0; ii < menuCount; ++ii) {
    combination.push_back(1);
  }
  return combination;
}

void orderCounter() {
  for (string order : orders) {
    sort(order.begin(), order.end());
    for (int courseMenuCount : course) {
      if (courseMenuCount > order.size()) continue;
      vector<int> combination = makeCombination(order, courseMenuCount);
      do {
        string menus;
        for (int i = 0; i < order.size(); ++i) {
          if (combination[i] == 1) {
            menus.push_back(order[i]);
          }
        }
        menuOrderedCount[courseMenuCount][menus]++;
      } while (next_permutation(combination.begin(), combination.end()));
    }
  }
}

void makeMenu() {
  for (int menuCount : course) {
    int maxOrderCount = 0;
    for (const auto &menus : menuOrderedCount[menuCount]) {
      maxOrderCount = max(maxOrderCount, menus.second);
    }
    if (maxOrderCount < 2) continue;

    for (const auto &menus : menuOrderedCount[menuCount]) {
      if (menus.second == maxOrderCount) {
        answer.push_back(menus.first);
      }
    }
  }
}

vector<string> solution(vector<string> inputOrders, vector<int> inputCourse) {
  orders = inputOrders;
  course = inputCourse;
  orderCounter();
  makeMenu();
  sort(answer.begin(), answer.end());
  return answer;
}