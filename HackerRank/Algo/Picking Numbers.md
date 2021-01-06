## c++

```c++
int pickingNumbers(vector<int> a) {
    int answer = 0;
    int numCounts[102] = {0};
    
    for(int num : a){
        numCounts[num]++;
    }
    
    for(int i = 0 ; i < 100; ++i){
        answer = max(answer, numCounts[i] + numCounts[i + 1]);
    }
    
    return answer;
}
```