#include <bits/stdc++.h>

using namespace std;

set<int> table;
set<int>::iterator cursor;
stack<int> removedNumbers;

vector<string> split(const string &str, const char &delimiter) {
  vector<string> ret;
  stringstream ss(str);

  string splitStr;
  while (getline(ss, splitStr, delimiter)) {
    ret.push_back(splitStr);
  }
  return ret;
}

void moveUp(int count) {
  while (count--) {
    cursor--;
  }
}

void moveDown(int count) {
  while (count--) {
    cursor++;
  }
}

string solution(int n, int k, vector<string> cmds) {
  for (int i = 0; i < n; ++i) {
    table.insert(i);
  }
  cursor = table.find(k);

  for (string cmd : cmds) {
    vector<string> splitCmd = split(cmd, ' ');
    if (splitCmd[0] == "U") {
      int count = stoi(splitCmd[1]);
      moveUp(count);
    } else if (splitCmd[0] == "D") {
      int count = stoi(splitCmd[1]);
      moveDown(count);
    } else if (splitCmd[0] == "C") {
      removedNumbers.push(*cursor);
      cursor = table.erase(cursor);
      if(cursor == table.end()){
        cursor--;
      }
    } else {
      int recoverNum = removedNumbers.top();
      removedNumbers.pop();
      table.insert(recoverNum);
    }
  }

  string answer(n, 'X');
  for(int num : table) {
    answer[num] = 'O';
  }
  return answer;
}
