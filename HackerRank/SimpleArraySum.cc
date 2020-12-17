#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the simpleArraySum function below.
 */
int simpleArraySum(vector<int> ar) {
    /*
     * Write your code here.
     */
     int sum = 0;
     for(int num : ar){
         sum += num;
     }
    return sum;
}