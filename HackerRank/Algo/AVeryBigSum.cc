#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the aVeryBigSum function below.
long aVeryBigSum(vector<long> ar) {
    long answer = 0;
    for(long l : ar){
        answer += l;
    }
    return answer;
}