## C++

```c++
bool isIntheRange(int houseStart, int houseEnd, int fruitLocation){
    return houseStart <= fruitLocation && fruitLocation <= houseEnd;
}

// Complete the countApplesAndOranges function below.
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int appleCount = 0;
    int orangeCount = 0;
    for (int appleDist : apples){
        if (isIntheRange(s, t, a + appleDist)) appleCount++;
    }
    
    for (int orangeDist : oranges){
        if (isIntheRange(s, t, b + orangeDist)) orangeCount++;
    }
    
    cout << appleCount << "\n";
    cout << orangeCount << "\n";
}
```


```java
    public static boolean isInTheRange(int houseStart, int houseEnd, int fruitLocation) {
        return houseStart <= fruitLocation && fruitLocation <= houseEnd;
    }

    // Complete the countApplesAndOranges function below.
    static void countApplesAndOranges(int s, int t, int a, int b, int[] apples, int[] oranges) {
        int appleCount = 0;
        int orangeCount = 0;
        for (int apple : apples) {
            if (isInTheRange(s, t, a + apple)) {
                appleCount++;
            }
        }

        for (int orange : oranges) {
            if (isInTheRange(s, t, b + orange)) {
                orangeCount++;
            }
        }
        System.out.println(appleCount);
        System.out.println(orangeCount);
    }
```