## c++

```c++
string kangaroo(int x1, int v1, int x2, int v2) {
    if (v2 >= v1) return "NO";
    int locationDiff = x2 - x1;
    int speedDiff = v2 - v1;
    
    if (locationDiff % speedDiff == 0) return "YES";
    else return "NO";
}
```

```java
    static String kangaroo(int x1, int v1, int x2, int v2) {
        int locationDiff = x2 - x1;
        int speedDiff = v1 - v2;
        if (speedDiff <= 0 || locationDiff % speedDiff != 0) {
            return "NO";
        }
        return "YES";
    }
```