## java

```java
class Practice {
    static int hurdleRace(int k, int[] heights) {
        int maxHeight = 0;
        for(int height : heights){
            maxHeight = Math.max(maxHeight, height);
        }

        int needDrinkCount = maxHeight - k;
        if(needDrinkCount <= 0) {
            return 0;
        } else{
            return needDrinkCount;
        }
    }
}
```