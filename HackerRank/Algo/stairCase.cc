#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.

void printStair(int n){
    for(int i = 0 ; i < n; ++i){
        cout << "#";
    }
}

void printBlank(int n){
    for(int i = 0 ; i < n; ++i){
        cout << " ";
    }
}

void staircase(int n) {
    for(int i = 1 ; i <= n; ++i){
        printBlank(n - i);
        printStair(i);
        cout << "\n";
    }
}
