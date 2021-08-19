#include <bits/stdc++.h>

using namespace std;

const string validateChars = ".-_";

string step7(string id) {
  string newId = id;
  while (newId.size() <= 2) {
    newId += newId.back();
  }
  return newId;
}

string step6(string id) {
  string newId = id;
  if (id.size() >= 16) {
    newId = newId.substr(0, 15);
  }
  if (newId.back() == '.') {
    newId.pop_back();
  }
  return newId;
}

string step5(string id) {
  if (id.empty()) {
    return "a";
  }
  return id;
}

string step4(string id) {
  if (!id.empty()) {
    if (id.front() == '.') {
      id.erase(id.begin());
    }
  }
  if (!id.empty()) {
    if (id.back() == '.') {
      id.pop_back();
    }
  }
  return id;
}

string step3(string id) {
  string newId = "";
  for (char ch : id) {
    if (ch != '.') {
      newId += ch;
      continue;
    }
    if (newId.empty() || newId.back() != '.') {
      newId += ch;
    }
  }
  return newId;
}

string step2(string id) {
  string newId = "";
  for (char ch : id) {
    if (isdigit(ch) || isalpha(ch) || validateChars.find(ch) != string::npos) {
      newId += ch;
    }
  }
  return newId;
}

string step1(string id) {
  for (char &ch : id) {
    ch = tolower(ch);
  }
  return id;
}

string solution(string newId) {
  string answer = step1(newId);
  answer = step2(answer);
  answer = step3(answer);
  answer = step4(answer);
  answer = step5(answer);
  answer = step6(answer);
  answer = step7(answer);
  return answer;
}