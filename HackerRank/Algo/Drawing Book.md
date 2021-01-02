## c++

```c++
int frontSeek(int p){
    return p / 2;
}

int reverseSeek(int n, int p){
    if (n % 2 == 0) n++;
    return (n - p) / 2;
}
int pageCount(int n, int p) {
    return min(frontSeek(p), reverseSeek(n, p));
}
```