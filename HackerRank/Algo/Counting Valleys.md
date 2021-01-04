## c++

```c++
int countingValleys(int steps, string path) {
    int vallyCount = 0;
    int curLocation = 0;
    for(char move : path){
        if (move == 'D') {
            curLocation--;
        }
        else {
            curLocation++;
            if(curLocation == 0) vallyCount++;
        }
    }
    return vallyCount;
}
```

## java

```java
    public static int countingValleys(int steps, String path) {
        // Write your code here
        int vallyCount = 0;
        int curLocation = 0;

        for (char move : path.toCharArray()) {
            if (move == 'U') {
                curLocation++;
                if (curLocation == 0) {
                    vallyCount++;
                }
            } else {
                curLocation--;
            }
        }
        return vallyCount;
    }
```