## c++

```c++
int birthday(vector<int> s, int targetSum, int targetLen) {
    deque<int> dq;
    int answer = 0;
    int dqSum = 0;
    for(int n : s){
        dqSum += n;
        dq.push_back(n);
        
        if(dq.size() < targetLen) continue;
        if(dqSum == targetSum) answer++;
        
        dqSum -= dq.front();
        dq.pop_front();
    }
    return answer;
}
```