# Best Time to Buy and Sell Stock II


## Cpp

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int benefit = 0;
        for(int i = 1 ; i < (int)prices.size(); ++i){
            if(prices[i] <= prices[i-1]) continue;
            benefit += prices[i] - prices[i-1];
        }
        return benefit;
    }
};
```

- 혼자 너무 어렵게 생각했다.
- 주식은 1개만 살수 있다는게 키포인트였다. 