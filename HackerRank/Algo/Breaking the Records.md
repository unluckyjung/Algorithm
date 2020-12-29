## c++

```c++
vector<int> breakingRecords(vector<int> scores) {
    
    const int MIN_INDEX = 1;
    const int MAX_INDEX = 0;
    
    int minScore = scores[0];
    int maxScore = scores[0];
    
    vector<int> answer(2,0);
    
    for(int i = 1; i < (int)scores.size(); ++i){
        int curScore = scores[i];
        
        if (curScore < minScore) {
            minScore = curScore;
            answer[MIN_INDEX]++;
        }
        if (curScore > maxScore) {
            maxScore = curScore;
            answer[MAX_INDEX]++;
        }
    }
    return answer;
}
```