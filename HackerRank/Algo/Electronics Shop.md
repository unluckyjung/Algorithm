## c++

```c++
int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    int totalMoney = b;
    int maxPrice = -1;

    for(const int &keyboardPrice : keyboards){
        for(const int &dirvePrice : drives){
            int needMoney = keyboardPrice + dirvePrice;
            if(needMoney > totalMoney) continue;
            maxPrice = max(maxPrice, needMoney);
        }
    }
    return maxPrice;
}
```


## java

```java
    static int getMoneySpent(int[] keyboards, int[] drives, int moneyLimit) {
        Arrays.sort(keyboards);
        Integer[] integerDrives = Arrays.stream(drives).boxed().toArray(Integer[]::new);
        Arrays.sort(integerDrives, Collections.reverseOrder());

        int maxPrice = -1;
        for (int drivePrice : integerDrives) {
            for (int keyboardPrice : keyboards) {
                int needMoney = keyboardPrice + drivePrice;
                if (needMoney > moneyLimit) {
                    break;
                }
                maxPrice = Math.max(maxPrice, needMoney);
            }
        }
        return maxPrice;
    }
```