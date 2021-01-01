## c++

```c++
int sockMerchant(int n, vector<int> ar) {
    vector<int> socks(100, 0);
    
    int pairCount = 0;
    
    for(int sock : ar){
        socks[sock]++;
        if (socks[sock] % 2 == 0) pairCount++;
    }
    
    return pairCount;
}
```


## java

```java
    static int sockMerchant(int n, int[] ar) {
        int pairSockCount = 0;
        Map<Integer, Integer> socks = new HashMap<>();

        for (int sock : ar) {
            if (socks.containsKey(sock)) {
                socks.put(sock, socks.get(sock) + 1);
            } else {
                socks.put(sock, 1);
            }
        }

        for (int sock : socks.keySet()) {
            int sockCount = socks.get(sock);
            pairSockCount += sockCount / 2;
        }
        return pairSockCount;
    }
```