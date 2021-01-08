## c++
> binary search Solution

```c++
int getRank(const vector<int> &rankedScoresSet, const int &playerScore){
    auto itr = upper_bound(rankedScoresSet.rbegin(), rankedScoresSet.rend(), playerScore);
    int rank = rankedScoresSet.rend() - itr;
    return rank + 1;
}
vector<int> climbingLeaderboard(vector<int> rankedScores, vector<int> playerScores) {
    vector<int> answer;
    rankedScores.erase(unique(rankedScores.begin(), rankedScores.end()), rankedScores.end());
    
    for(const int &playerScore : playerScores){
        answer.push_back(getRank(rankedScores, playerScore));
    }
    return answer;
}
```

* 레퍼런스로 안넘기면 복사가 일어나서, 시간초과가 발생한다.