## c++

```c++
int migratoryBirds(vector<int> arr) {
    int maxSight = 0;
    
    vector<int> birdSightCount(6,0);
    
    for(int birdType : arr) {
        birdSightCount[birdType]++;
        maxSight = max(maxSight, birdSightCount[birdType]);
    }
    
    
    for(int birdType = 1; birdType <= 5; ++birdType){
        if(birdSightCount[birdType] == 0) continue;
        if(birdSightCount[birdType] == maxSight) return birdType;
    }
    
    return -1;
}
```