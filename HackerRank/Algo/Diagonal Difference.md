## c++

```c++
int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size();
    int leftToRight = 0;
    int rightToLeft = 0;
    
    for(int i = 0; i < n; ++i){
        leftToRight += arr[i][i];
        rightToLeft += arr[i][n-1-i];
    }
    
    return abs(leftToRight - rightToLeft);
}
```

## java

```java
    public static int diagonalDifference(List<List<Integer>> arr) {
    // Write your code here
        int n = arr.size();
        int leftToRight = 0;
        int rightToLeft = 0;
        for (int i = 0; i < n; ++i) {
            leftToRight += arr.get(i).get(i);
            rightToLeft += arr.get(i).get(n - 1 - i);
        }
        return Math.abs(leftToRight - rightToLeft);
    }
```