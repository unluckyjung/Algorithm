## c++

```c++
int divisibleSumPairs(int n, int k, vector<int> ar) {
    
    int answer = 0;
    for(int i = 0; i < n; ++i){
        for(int ii = i + 1;  ii < n; ++ii){
            int num1 = ar[i];
            int num2 = ar[ii];
            
            if((num1 + num2) % k == 0) answer++;
        }
    }
    return answer;
}
```