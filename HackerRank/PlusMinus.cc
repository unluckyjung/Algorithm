#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the plusMinus function below.
void plusMinus(vector<int> arr) {
    int positiveNumCount = 0;
    int zeroCount = 0;
    int negativeNumCount = 0;
    
    for(int num : arr){
        if(num > 0) positiveNumCount++;
        else if(num == 0) zeroCount++;
        else negativeNumCount++;
    }
    cout << fixed;
    cout.precision(6);
    
    cout << positiveNumCount / double(arr.size()) << "\n";
    cout << negativeNumCount / double(arr.size()) << "\n";
    cout << zeroCount / double(arr.size()) << "\n";
}