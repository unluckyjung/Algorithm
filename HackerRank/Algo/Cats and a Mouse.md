## c++

```c++
string catAndMouse(int x, int y, int z) {
    int catA = abs(z - x);
    int catB = abs(z - y);
    
    if (catA == catB) return "Mouse C";
    if (catA < catB) return "Cat A";
    return "Cat B";
}
```