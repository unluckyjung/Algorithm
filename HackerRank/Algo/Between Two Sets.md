## C++

```c++
bool isCanDivide(vector<int> b, int lcmInt){
    for(int num : b){
        if(num % lcmInt != 0) return false;
    }
    return true;
}
 
int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int lcm(long long a, int b){
    return a * b / gcd(a,b);
}

int getTotalX(vector<int> a, vector<int> b) {
    int lcmInt = 1;
    int answer = 0;
    
    for(int num : a){
        lcmInt = lcm(lcmInt, num);
    }
    
    for(int i = lcmInt; i <= 100; i += lcmInt){
        if(isCanDivide(b, i)) answer++;
    }
    return answer;
}
```