#include <bits/stdc++.h>

using namespace std;

char getGrade(double evgScore) {
  if (evgScore >= 90 || abs(evgScore - 90.0) < 0.00001) return 'A';
  if (evgScore >= 80 || abs(evgScore - 80.0) < 0.00001) return 'B';
  if (evgScore >= 70 || abs(evgScore - 70.0) < 0.00001) return 'C';
  if (evgScore >= 50 || abs(evgScore - 50.0) < 0.00001) return 'D';
  return 'F';
}


double getScore(vector<int> score, int studentNumber) {
  // 학생들이 자기 자신을 평가한 점수가 유일한 최고점 또는 유일한 최저점

  double ret = 0.0;
  int count = score.size();
  map<int, int> scoreCount;

  for (int s : score) {
    scoreCount[s]++;
    ret += s;
  }

  int minScore = scoreCount.begin()->first;
  int maxScore = scoreCount.rbegin()->first;

  int selfSelectScore = score[studentNumber];
  if (selfSelectScore == minScore || selfSelectScore == maxScore) {
    if (scoreCount[selfSelectScore] == 1) {
      ret -= selfSelectScore;
      count--;
    }
  }


  return ret / count;
}

string solution(vector<vector<int>> scores) {

  string answer = "";

  for (int i = 0; i < scores.size(); ++i) {
    vector<int> studentScore;
    for (int ii = 0; ii < scores[0].size(); ++ii) {
      studentScore.push_back(scores[ii][i]);
    }

    double evgScore = getScore(studentScore, i);
    answer.push_back(getGrade(evgScore));
  }

  return answer;
}